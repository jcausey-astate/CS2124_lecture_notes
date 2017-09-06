# CS2124
## Copy Constructors
### (Chapter 14 Sections 14.3, 14.4)

---

## First, something new...
### Constructor initialization lists

A constructor's job is to initialize attributes of the class:
``` cpp
class Rectangle {
    public:
        Rectangle (int l, int w){
            length = l;
            width  = w;
        }
        int length = 0;
        int width  = 0;
};
```

---

## Constructor initialization lists

But... there is another way to do it:

``` cpp
class Rectangle {
    public:
        Rectangle (int l, int w) : length{l}, width{w} {}
        int length = 0;
        int width  = 0;
};
```

This:

``` cpp
 : length{l}, width{w}
```
Is the _constructor initialization list_.  It is followed in this case by an _empty_ method body `{}`, which is OK, since there is nothing more for this constructor to do.

* The initialization list takes effect _before_ the body of the c-tor method begins to execute!
* There is no scope resolution ambiguity in an initialization list.

---

## Memberwise Assignment

Given:
``` cpp
class Rectangle {
    public:
        Rectangle (int l, int w) : length{l}, width{w} {}
        int length = 0;
        int width  = 0;
};
```

What happens when you do:

``` cpp
Rectangle r1{3, 4};
Rectangle r2 = r1;
```

---

## Memberwise Assignment

What happens when you do:

``` cpp
Rectangle r1{3, 4};
Rectangle r2 = r1;
```

Each attribute in `r2` receives a copy of the corresponding attribute in `r1`.

When can this be a problem???

---

## Copy Constructor

The _Copy Constructor_ is called in cases where a copy of an object is being created on-the-fly. 

``` cpp
MyClass a;
MyClass b = a;
```

* Called in these cases:
    - When an object is returned by value
    - When an object is passed (to a function) by value as an argument
    - When an object is thrown
    - When an object is caught
    - When an object is placed in a brace-enclosed initializer list

---

## Copy Constructor

* Commonly takes a `const` reference to an object of the same class as a parameter.
* __Must__ take a reference, but may not always be `const`.

``` cpp
MyClass{
    public:
        MyClass(const MyClass& orig); // copy c-tor
    [...]
};
```

---