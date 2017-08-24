# CS2124

## Objects (Chapter 13)

---

## Specification and Implementation

* Header files ( _`.h`_ ) – place class specification here
* Implementation file ( _`.cpp`_ ) – implement methods here
* The `#include` directive with a path
* Implementation ( _`.cpp`_ ) files can be compiled;
* header files cannot.
* Do not `#include` a _`.cpp`_ file!

---

## Inline Methods

* Defined directly in class specification.
* Substituted during compilation.
* Speed VS executable size
* _"inline all 1-liners"_
* `inline` keyword

---

## Pointers to Objects

* Uses same pointer notation
* "_dot-notation_" becomes "_arrow-notation_":
    - Arrow operator (  `->`  )
* Dynamic allocation of objects is possible
* Review `new` and `delete`

---

## Constructors

* Called when object is created.
* Responsible for building object and putting it in a working state.
* Same name as class name
* No return type.
* Default constructor requires no parameters.
* Constructors may require parameters.
* A class may not have a default constructor.

---

## Destructors

* Called when object is destroyed
    - Either being deleted or going out of scope
* Named same as class, but begins with `~`
* No return value
* No parameters
* Cannot be overloaded
* When and why destructors are needed

---

## Overloading

* Constructors may be overloaded
    - Consequences for default constructor
* Methods may be overloaded
* Destructors may NOT be overloaded

---

## Details

* Timing of constructors, destructors
* “normal objects” and dynamically-allocated objects
* Private methods – what good are they?
* Arrays of objects
* Requires default constructor ...
    - ... unless array initializer syntax is used.
* May provide arguments only or constructor invocations.
