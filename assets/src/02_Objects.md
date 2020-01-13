# CS2124

## Objects (Chapter 13)

---

## Separating *Specification* and *Implementation*

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
    - Operators `new` and `delete` (coming soon...)

---

## Destructors

* Called when object is destroyed
    * Either by being deleted or going out of scope
* Named same as class, but begins with `~`
* No return value, no parameters
* Cannot be overloaded
* ... when and why destructors are needed

---

## Overloading
* Constructors may be overloaded
    - Consequences for default constructor
* Methods may be overloaded
* Destructors _may NOT_ be overloaded

---

## Details

* Timing of constructors, destructors
* "normal objects" and dynamically-allocated objects
* Private methods – what good are they?
* Arrays of objects
    - Requires default constructor ...
    - ... unless initialization syntax is used.
        * May provide arguments only or constructor invocations.
