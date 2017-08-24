# CS2124

## Classes and Objects

---

## Introduction

* Procedural (structured) Programming
    - Concerned with processes (_actions_) that occur in a program.
* Object-Oriented Programming (OOP)
    - Focuses on the data (_things_) and the functions that operate on it.

---

## OOP Concepts

* Encapsulation
    - Bundling
    - Data hiding
* Public Interface

---

## OOP Terminology

_**Class**_ - basically like a _structure_, but allows functions to be encapsulated as well as data.

* The class is the _blueprint_ describing the new type of thing.

_**Object**_ - an instance of a class.

* The object is the real thing that is built by following the blueprint.

_**Attributes**_ - a class's _member data_

_**Methods**_ - a class's _member functions_


---

## Format of a Class

```cpp
class ClassName 
{
    declaration;
    declaration;
};
```

**Example**

```
struct Rectangle {  |   class Rectangle {
    double length;  |       public:
    double width;   |           double length;
    double area;    |           double width;
};                  |           double area();
                    |   };
```

---

## Access Specifiers

**`public`** - Available both inside and _outside_ the class definition.

**`private`** - Only available _inside_ the class definition.

**`protected`** - Similar to `private` (we'll see this later).

* Order doesn't matter.
* Default is `private`

---

## Methods

* Prototype in _class declaration_
* Definition usually in separate _implementation file_.
    - May also be in same file.
* _Scope resolution operator_ ( `::` ) – used to establish ownership of an identifier
    - Must be used when splitting method definitions from the class declaration.

---

## Accessors and Mutators

* Provides a way to safely access data members.
* Principle of _least privilege_.
* Stale data (Avoid it!)
* Allows the class to disallow incorrect states.

---

## Constructors

* Allow an object to be _instantiated_ (created) in an already-working state.
    - Contrast this with the _uninitialized_ state that regular data and `struct`s begin with.
* Constructors _do not_ have any return type.
* Constructors have the same name as the class.
* _Default constructor_ is a constructor that takes no parameters; used to create a "default" or "blank" object.
* Constructors may take parameters to allow _initialization_ during instantiation.
* A class may not have a default constructor.

---

# Class and Object Details

The next section will cover details concerned with including `class` definitions in your projects.

---

## Specification and Implementation

* Header files ( _`MyClass`_`.h` ) – place class specification (declaration) here
* Implementation file ( _`MyClass`_`.cpp` ) – implement methods here
* `#include` the header from the implementation file
* Implementation ( `.cpp` ) files can be compiled; header files cannot.
* **NEVER** `#include` a `.cpp` file!

---

## Inline Methods

* Implemented directly in class specification.
* Substituted during compilation.
* Speed VS executable size
* “inline all 1-liners”
* `inline` keyword
    - Can be used to inline functions implemented separately.

---

## Pointers to Objects

* Uses same pointer notation
* “dot-notation” becomes “arrow-notation”:
* Arrow operator (  `->`  )
* Dynamic allocation of objects is possible
    - Review `new` and `delete`

---

## Destructors

* Called when object is destroyed
* Either being deleted or going out of scope
* Named same as class, but begins with `~`
* No return value, no parameters.
* Cannot be overloaded
* When and why destructors are needed

---

## Overloading
* Constructors may be overloaded
    - Consequences for default constructor
* Methods may be overloaded
* Destructors _may NOT_ be overloaded

---

## Details

* Timing of constructors, destructors
* “normal objects” and dynamically-allocated objects
* Private methods – what good are they?
* Arrays of objects
    - Requires default constructor ...
    - ... unless array initializer syntax is used.
        * May provide arguments only or constructor invocations.





