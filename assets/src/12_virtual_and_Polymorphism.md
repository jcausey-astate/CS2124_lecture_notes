# Virtual Methods 
# & Polymorphism
## (Ch 15.4)

---


## Redefining Base Class Methods

* A method is said to be _redefined_ in a derived class when it has the same name (and perhaps parameter list) as a method in the base class.
    * This is not the same thing as _overloading_.
* Base class objects use the base class method... derived class objects use the derived class method.

---

## Problem with Redefining

Consider this situation:

* Class `BaseClass` defines methods `x()` and `y()`.<br />   `x()` calls `y()`. 
* Class `DerivedClass` inherits from `BaseClass` and redefines method `y()`.
* An object `D` of class `DerivedClass` is created and method `x()` is called.
* When `x()` is called, which `y()` is used; the one defined in `BaseClass` or the the redefined one in `DerivedClass`?

---

<small style="font-size: 80%;">

```cpp
#include <iostream>
    
class BaseClass{
  public:
    void x() { 
        std::cout << "BaseClass::x()\n";
        y();
    }
    void y() {
        std::cout << "BaseClass::y()\n";
    }
};

class DerivedClass : public BaseClass {
  public:
    void y() {
        std::cout << "DerivedClass::y()\n";
    }
};

int main() {
    DerivedClass d1;
    d1.x();  // what is the output?
    return 0;
}
```

</small>

---

## Problem with Redefining

Answer to the riddle:

* The BASE class’s `y()` method is called!
    - This isn’t what you _want_...
    - but it should be what you _expect_...
* From `x()` in the base class’s point-of-view (at compile time), the only available `y()` is its own.
* Compiler binds the method call in `x()` to the base class `y()` at compile time... Once it’s done, it’s done.
* This is called _static binding_

---

## Class Hierarchies

* A derived class can also be used as a base class.
* This (of course) complicates issues like method redefining...

---

## Virtual Methods

_**Virtual Method**_: a method in a base class that _expects_ to be redefined in derived classes.

* Defined with keyword   `    virtual   `
```cpp
virtual void y();
```
* Allows _dynamic binding_ – method name bound _at runtime_ to the corresponding code. ( as opposed to static binding )
    - Dynamic binding is based on the _type_ of the object actually initiating the call at runtime.

---

<small style="font-size: 80%;">

```cpp
#include <iostream>
    
class BaseClass{
  public:
    void x() { 
        std::cout << "BaseClass::x()\n";
        y();
    }
    virtual void y() { // NOTE: virtual method
        std::cout << "BaseClass::y()\n";
    }
};

class DerivedClass : public BaseClass {
  public:
    virtual void y() { // virtual because BaseClass::y() is...
        std::cout << "DerivedClass::y()\n";
    }
};

int main() {
    DerivedClass d1;
    d1.x();  // will work as desired now.
    return 0;
}
```

</small>

---

## Polymorphism

A pointer of the base-class type may be "pointed" to a derived class object.

* Remember the "is-a" relationship...
    - Base-class pointers can only access members defined in the base class.
    - This won’t work in reverse!
* When the base class uses dynamic binding... 
    - Base class pointer to derived class object behaves appropriately for the derived class.
    - This is called _polymorphism_.
* Polymorphism requires a pointer or reference.

---

<small style="font-size: 75%;">

```cpp
#include <iostream>
    
class BaseClass{
  public:
    void x() { 
        std::cout << "BaseClass::x()\n";
        y();
    }
    virtual void y() {
        std::cout << "BaseClass::y()\n";
    }
};

class DerivedClass : public BaseClass {
  public:
    void y() {
        std::cout << "DerivedClass::y()\n";
    }
};

int main() {
    BaseClass* d2 = new DerivedClass;
    d2->x();   // will behave as DerivedClass
    delete d2;
    return 0;
}
```

</small>

---

## Redefining VS Overriding

_**Redefining**_: refers to statically-bound methods.    
_**Overriding**_: refers to dynamically-bound methods.

* Redefined methods _**do not**_ exhibit polymorphic behavior
* Overridden methods _**do**_ exhibit polymorphic behavior.

---

## When to Use `virtual`

Whenever you think a derived class might want to override a method!

* Yes, there is a performance cost...
    - Dynamic binding requires a runtime "vtable" - a look-up table where the virtual function mapping is determined.
* Destructors – (almost) Always a good idea to make these `virtual`!
    - If a class _might_ be used as a base class, it is recommended to make the destructor `virtual`.

---

## Pure `virtual` Methods

_**Pure `virtual` method**_: a method that is not implemented (at all) in the base class, and is thus _required_ to be overridden in derived classes.

* Created by using "assignment" syntax:
``` cpp
virtual void y() = 0;
```
* The "`= 0`" tells the compiler "this is a pure virtual method&mdash;don’t expect an implementation".

---

## Abstract Base Classes

_**Abstract base class**_: a base class that contains at least one pure virtual method.

* Useful for factoring out common behavior from a _family_ of objects.
    - For providing a _required common interface_.
* You _cannot_ instantiate an object from an abstract base class.
* You _can_ create pointers to abstract base classes (useful for polymorphic behavior).

---

## Multiple Inheritance

* Multiple base classes
* Inherit from all base classes (may result in multiple attributes/methods with same name)
* Scope resolution will be required.

![Multiple Inheritance](assets/images/virtual_Polymorphism/multi_inherit.png )
