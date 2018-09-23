## `friend` Functions  
## Operator Overloading

---

## Friends of Classes

* A function or class may be declared to be a `friend` of a new class.  
    - Created by adding the `friend` type modifier to the front of a declaration/prototype.
* Declaring a function or class as a friend gives that function/class access to the private data in the class being defined.
* __*Use this sparingly!*__

If you find yourself needing a `friend` function/class, you could probably _design your class better_ and avoid the problem.

---

## Memberwise Assignment
* When using `=` to assign one object to another...
    - Each member is assigned directly (by copy) from the class on the right to the one on the left.
    - This is often the desired outcome... but not always!
        + (reference types like arrays can cause problems)
* Two parts to the solution:
    - Copy Constructor
    - Overloaded assignment operator

---

### Review: Operator Overloading

* Almost all operators in C++ can be overloaded (see book).
* Many can be overloaded as class methods.
    - Some, like `=` and `[]` can _only_ be overloaded as class methods.
    - Overloading as methods helps keep class-related code _encapsulated_ in the class.

---

### Review: Operator Arity

* **Unary Operators** --- Operators with __one__ operand.
    - Examples: negation, logical "not"
* **Binary Operators** --- Operators with __two__ operands.
    - Examples:  addition, subtraction, multiplication, division, etc.
* **Ternary Operators** --- Operators with __three__ operands.
    - Example:  The `?:` _conditional_ operator.
    - Cannot be overloaded.

---

### Review: Operator Overloading

Function name is just "`operator`" followed by the symbol for the operator being overloaded (space optional).

**Examples**

`operator+`

`operator*`

`operator/`

`operator-`

`operator<<`

---

### Review Example: `struct Vector2D`

In Structured Programming, you developed a `Vector2D` data type using a `struct`.  It contained an `x` and `y` attribute (integers):

``` cpp
struct Vector2D {
    int x;
    int y;
};
```

---

### Review: Stand-Alone Op. Functions

The following examples use the `Vector2D` type for demonstration.

**Binary** (the most common type):

``` cpp
// Handle expressions similar to:  v1 + v2
Vector2D operator+ (const Vector2D& left, 
                    const Vector2D& right);
```
Note how the left-hand and right-hand operands become parameters.

---

### Review: Stand-Alone Op. Functions

**Unary**:

``` cpp
// Handle expressions similar to:  -v1
Vector2D operator- (const Vector2D& right);
```
For unary operators, there is only one operand involved, and it is usually the right-hand side.

---

**`class Vector2D`:**  `class Vector2D` will be used in the following slides:

<small style="font-size: 77%;">

``` cpp
using std::ostream;

class Vector2D {
public:
    // default c-tor (zero x and y using universal 
    // initializer syntax in the c-tor initialization 
    // list).
    Vector2D()             : x{0}, y{0} { }
    // overloaded c-tor allows construction given an 
    // x- and y- component value.
    Vector2D(int x, int y) : x{x}, y{y} { }

    // [...] other operators prototyped here...

    // as seen in class, stream insertion may be 
    // designated a `friend` to allow access to 
    // private attributes `x` & `y`.
    friend ostream& operator<< (ostream& s, 
                                const Vector2D& v);
private:
    int x;
    int y;
};
```

</small>

---

### Binary Operator Methods

When overloading a binary operator in a `class` method, the _object itself_ __always__ takes the "left-hand" position:

**Example:**

```cpp
class Vector2D {
public:
    [...]

    // Addition:   v1 + v2
    Vector2D  operator+ (const Vector2D& right);
    
    [...]
};
```

---

### `const` Methods

Previous slide prototype has a problem:
``` cpp
Vector2D  operator+ (const Vector2D& right);
```
This specifies that the right- operand must remain unchanged ...    
But the left- operand (the object iself) _should also_ remain unchanged!    
Mark _methods_ as `const` to indicate the object's state is not modified by the method:
``` cpp
Vector2D  operator+ (const Vector2D& right) const;
```
Note the keyword `const` __following__ the parameter list. This creates a _`const` method_.  The method __must not__ modify the object (`this`).

---

### `class Vector2D` Now:

<small style="font-size: 77%;">

``` cpp
using std::ostream;

class Vector2D {
public:
    // default c-tor (zero x and y using universal 
    // initializer syntax in the c-tor initialization 
    // list).
    Vector2D()             : x{0}, y{0} { }
    // overloaded c-tor allows construction given an 
    // x- and y- component value.
    Vector2D(int x, int y) : x{x}, y{y} { }

    // overloaded addition:  v1 + v2
    Vector2D  operator+ (const Vector2D& right) const;

    // as seen in class, stream insertion may be 
    // designated a `friend` to allow access to 
    // private attributes `x` & `y`.
    friend ostream& operator<< (ostream& s, 
                                const Vector2D& v);
private:
    int x;
    int y;
};
```

</small>

---

### Implement `Vector2d::operator+`

Now implement the method `Vector2d::operator+`.

* Addition of vectors involves adding the $x$- and $y$- component of the left and right operands together:
    - $a + b = \langle a_x+b_x, a_y+b_y \rangle$ 

---

### Unary Operator Methods

When overloading a unary operator in a `class` method, the _object itself_ is being operated upon, and there are __no__ additional parameters.

**Example:**

```cpp
class Vector2D {
public:
    [...]

    // unary `-` : invert vector
    Vector2D  operator- ( ) const; 
    
    [...]
};
```

---

### Implement `Vector2d::operator-` (unary)

Now implement the unary operator method `Vector2d::operator-`.

* Inversion of vectors involves reversing the direction of both the $x$- and $y$- components:
    - $-a = \langle -a_x, -a_y \rangle$ 

---

### Follow the Pattern

Other unary and binary operators are overloaded the same way.

* Determine the proper return type.
* The object is on the left (for binary)
* Most operators don't change the operands
    - (so use `const` methods and pass by `const` ref.)

**Q:** What would happen if you had a non-class item on the left of a binary operation?

**Example:**
``` cpp
Vector2D v1{2, 4};
// What would the expression 3 * v1   do?
```

---

## Operator Overloading

Here are some operators that don't "follow the pattern":

* Binary operators where there is an object that is **not** a member of your class on the *left*.
    - Overload these as stand-alone functions.
* Stream operators: `<<` and `>>`
    - Really, this is just an example of the previous point: The item on the left is a *stream* object.
    - Be careful with the stream parameter and return value --- use references! (Never make a copy of an open stream.)
* `++` and `--`
    - Remember, there is a "pre" and "post" version of each!
* Array operator `[]`

---

### Binary operators with non-class member on left

Example:  Multiply a real number and a vector:  `2.5 * v` where `v` is a `Vector2D`.

```cpp
Vector2D operator* (int lhs, const Vector2D& rhs);
```

Note that this is *not* a method of class `Vector2D` --- it must be implemented as a stand-alone function.

Try to make use of the fact that `2.5 * v` is the same as `v * 2.5` to avoid repeating code.

---

### Stream Operators

The stream operators `>>` and `<<` always have a *stream* object on the left, and always *return the stream*. Consider how the following expression would be evaluated:

```cpp
std::cout << "Have some " << 3.14 << '\n';
```

<small>The `<<` operators associate left-to-right, so `cout << "Have some "` executes first, then returns `cout`, which is applied to the left of `<< 3.14`, and so on.</small>

Example: Prototype for stream insertion of `Vector2D`:

```cpp
std::ostream& operator<< (std::ostream& strm, const Vector2D& v);
```

---

### `++` and `--`

Incrementing and decrementing vectors doesn't make much sense, so let's use a `ComplexNumber` class defined like so:

```cpp
class ComplexNumber{
public:
    ComplexNumber(double real_part, double imaginary_part);
    // ... other methods here
private:
    double real_part      = 0;
    double imaginary_part = 0;
};
```

---

### `++` and `--` : Prefix version

The expressions `++x` and `--x` increment and decrement `x`, respectively.  The increment happens before the value is returned, so they evaluate to the *modified* value of x.  Say `x` is a `ComplexNumber` with real part 2 and imaginary part 0:

```cpp
std::cout << x << ' ' << ++x << ' ' << x << '\n';
// should print "2+0i 3+0i 3+0i", making some reasonable assumptions 
// about overloading the `<<` operator.
```
The prefix increment operator is *unary*, so it makes sense that its prototype (as a member of `ComplexNumber`) would be:

```cpp
ComplexNumber operator++ (ComplexNumber& num);
// Non-const reference!  This method _does_ change the object.
```

The decrement operator works the same, only it subtracts 1 instead of adding.

---

### `++` and `--` : Postfix version

The expressions `x++` and `x--` increment and decrement `x`, respectively.  But in this case, the value that is returned is the original value (before increment/decrementing).  Say `x` is a `ComplexNumber` with real part 2 and imaginary part 0:

```cpp
std::cout << x << ' ' << ++x << ' ' << x << '\n';
// should print "2+0i 2+0i 3+0i"
```

<small style="font-size: 90%;">The postfix increment operator is **also** *unary* --- and this causes an ambiguity.  How can the compiler tell one unary operator with the symbol `++` from another?  

They "cheat".  The language specification introduces a "dummy" parameter of type `int` as a second parameter of the *postfix* increment and decrement.  So the prototype for postfix increment is:</small>

```cpp
ComplexNumber operator++ (ComplexNumber& num, int);
// Notice the "dummy" parameter - not used in the function code for 
// anything, so no need to name it.
// It is there to signal to the compiler that this is the "postfix" increment.
```

---

### Array operator `[]`:

Imagine a `MyArray` class defined similarly to what we did earlier in the semester.  We defined an `at()` method to allow access to individual elements.

But, C++ allows us to overload the `[]` operator so that our array class can be used the way we expect for an array --- with "bracket" indexing.

`[]` is a *binary* operator (even though it looks odd).  The "left"-hand side is the array object.  The "right"-hand side is the value inside the brackets (normally an `int`).  So the prototype might look like this:

```cpp
int& operator[] (int index);
// Notice the return-by-reference:  This allows us to do e.g. `x[3] = 8;`
```











