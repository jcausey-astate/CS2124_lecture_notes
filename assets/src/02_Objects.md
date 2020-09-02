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

## Constructors

* Allow an object to be _instantiated_ (created) in an already-working state.
    - Contrast this with the _uninitialized_ state that regular data and `struct`s begin with.
* Constructors _do not_ have any return type.
* Constructors have the same name as the class.
* _Default constructor_ is a constructor that takes no parameters; used to create a "default" or "blank" object.
* Constructors may take parameters to allow _initialization_ during instantiation.
* Classes do not always have a default constructor.

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
    - Remember that there are consequences for default constructor
* Methods may be overloaded
* Destructors _may NOT_ be overloaded

---

## Uniform Initialization Syntax
* Added in C++11
* Allows initialization of all types of variables with the same syntax.
* The "old" syntax for each type still works, but consider using uniform syntax.

**Syntax:**
`variableType  variableName{argument1, argument2};`

**Example:**
```cpp
int       age{23};
Rectangle classroom{24, 30};
// The following is an array - we will talk more about these soon:
double    temperatures[]{78.8, 80.2, 92.4, 87.5, 95.3, 95.1, 92.8};
```

---

## Details

* Timing of constructors, destructors
* "normal objects"
* Sneek peek: Pointers to objects, and `this` keyword.
* Arrays of objects
    - Requires default constructor ...
    - ... unless initialization syntax is used.
        * May provide arguments only or constructor invocations.

---

## Constructor initialization list syntax

* Compact syntax for placing values into attributes in a constructor implementation.
* Only works with constructors.
* Guarantees initialization *before* body of constructor executes.

**Example**

```cpp
struct Rectangle{
    Rectangle(int l, int w) : length{l}, width{w} {}
    int length;
    int width;
};
```

The body of the constructor above is _empty_ since there is no more initialization work to do... But the body (curly braces) is still required syntactically.

