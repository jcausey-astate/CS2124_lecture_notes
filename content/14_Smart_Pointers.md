---
title: "14_Smart_Pointers"
date: 2020-10-02T12:30:16-05:00
draft: false
marp: true
---

## Smart Pointers
### (Ch. 9.10)

---

## Owner's Remorse

Dynamic memory allocation in C++ requires that a pointer be used to manage the dynamic resource.

* We refer to such pointers as _owning_ pointers.
* If a _raw pointer_ (regular C++ pointer type) is used as an owning pointer, there is no guarantee that the managed resource will be freed.

Freeing the managed resource is the _responsibility of the programmer_.

---

## The OOP Way

The main advantage of objects is in their ability to self-initialize and safely destruct.

* If an owning pointer "knew" it was an owning pointer, it could free the managed resource during destruction.
* Creating an object-based pointer specifically for use as an owning pointer is an attractive solution...

---

## RAII (review)

* _**Resource Allocation Is Initialization**_ (RAII) is a term coined by Bjarne Stroustrup (the creator of C++).  
* It refers to the fact that resources should be _allocated_ during the _initialization_ phase of object instantiation (construction).
* Also implied is the concept that resource lifetime should be determined by object lifetime.

**To summarize:**

The constructor initializes resources to be managed by the object until its destructor deallocates them.

---

## C-Legacy VS Modern C++

The object-oriented aspects of C++ follow the RAII idiom; however, the "C-legacy" parts of the language do not.

* Raw pointers are a prime example. They can be owners of resources _or_ passive observers of resources &mdash; no way to tell the difference!
* This leads to errors and memory leaks, not to mention code that is hard to maintain.

---

## "Smart Pointers"

Owning pointers can be improved by simply "wrapping" them with an object.

![Smart Pointer](../images/Smart_Pointer/SmartPointer_simple.png)

* The _object_ becomes responsible for allocating the resource (during construction) and deallocating it (during destruction).  
* The lifetime of the managed resource will be identical to the _lifetime of the object_.

---

## C++ Standard Smart Pointers

Starting in C++11, smart pointers have been added to the C++ standard library in the `<memory>` header.

* `std::unique_ptr` - Takes singular (non-shared) ownership of a resource.
* `std::shared_ptr` - Assumes shared ownership of a resource.
* `std::weak_ptr` - A non-owning pointer that can be converted to a `shared_ptr` when access to the resource is required.

We will take a closer look at `unique_ptr` and `shared_ptr`.

---

## Unique Pointer

The C++ `std::unique_ptr` is defined in `<memory>`.  It represents a smart pointer that assumes singular ownership of a resource.

**How it works:**

* During construction, assume ownership of the resource.
* Expose the operations expected for a pointer.
    * dereference, arrow, and (maybe) array-index; maybe others...
* During destruction, de-allocate the managed resource.

---

## Shared Pointer

Implemented as a _reference counting_ pointer, meaning that the resource will not be deleted as long as at least one reference to it (via a `shared_ptr`) still exists.

**How it works:**

* During construction, assume ownership of the resource.
    * If this is the first instance, set reference count to 1.
    * If this is a copy, increment the reference count.
* Expose the operations expected for a pointer.
    * dereference, arrow, and (maybe) array-index; maybe others...
* During destruction, decrement the reference count.
    * If the reference count has gone to 0, delete the managed resource.

---

## Our Own Unique Pointer

We could create a unique pointer that follows RAII even more closely than the `std::unique_ptr`...

* Instead of taking ownership of a resource via pointer, ours will actually _allocate and instantiate_ the resource.

---

## Construction

* During construction, allocate new memory to contain the data value (passed into a parameter).
* Disallow copy construction (and assignment)!

---

## Destruction

* Just de-allocate the managed object...

---

## Pointer Behaviors

* Dereference: `operator*()` (unary)
* Arrow: `operator->()` (unary)
    * Really? Unary?

---

## Dereference

Prototype:
```cpp
Foo& operator*() const;
```
* The dereference operator is unary and should just return the result of dereferencing the internal raw pointer attribute.
* The value should be returned by reference to allow write-access.

That's it!

---

## Arrow

Arrow is a little bit unusual...  The prototype is:
```cpp
Foo* operator->() const;
```

<blockquote style="font-size: smaller;">... Wait a minute - Why unary?  Why just return the _raw pointer_? </blockquote>

* The compiler will arrange for the arrow operator to be **re-applied** to the pointer that is returned!

```cpp
UniquePtr myPtr;        // with UniquePtr object,
myPtr->doSomething();   // invoke via arrow
```
This is how the compiler applies the operator:
```cpp
(myPtr.operator->())->doSomething();
```

---

## Make it Generic!

Our `UniquePtr` should really work for _any_ kind of data...

```cpp
template <class DType> 
class UniquePtr {
    // [...]
};
```

* Challenge
    - Construction: Managed object constructors may allow _any number and type_ of parameters!
        + How can we possibly write code to allow this?

---

## Variadic Templates

* We need some way to pass along _any number of arguments_, of _any type_ to the constructor of the underlying managed object.
* C++ allows _variadic templates_ (AKA: "_parameter pack_") to deal with this kind of situation.

```cpp
template <typename... ArgType>
UniquePtr(const ArgType&... args)   
    { _ptr = new DType{ args... };  }
```

> <small>The ellipsis ( `...` ) indicates that any number of arguments may match the "pattern" for that template parameter.</small>

---

## Template Specialization

Our `UniquePtr` works fine for pointers to single objects, but we also need to be able to manage arrays.

* deallocation requires `delete []`
* `operator[]()` should be supported

_Template Specialization_ allows us to create a custom copy of `UniquePtr` that can manage an array:

```cpp
template <class DType>
class UniquePtr< Dtype[] > {
    // [...]
};
```
Notice the template argument provided to specialize this template so that it is matched when the _array type modifier_ is present.  The underlying type is still generic.

---

## Our Own Shared Pointer

A shared pointer adds _copy_ functionality.  The managed resource will remain viable as long as at least one copy of the pointer refers to it.

* This requires us to maintain a _shared reference count_ for all copies of a pointer to a particular resource.
    - How do we share it?

---

## Shared Pointer Details

* **Reference count** attribute must by dynamically-allocated (actual attribute is a pointer to the count).
* **Main c-tor:** allocates the managed object and the reference count.  Initialize ref count to 1.
* **Copy c-tor / assignment op.:**  make a shallow-copy of the object, then increment the reference count.
* **d-tor:** Decrement the reference count.  If ref count is now 0, delete the managed resource _and_ the reference count.

All other methods look the same as for `UniquePtr`.
