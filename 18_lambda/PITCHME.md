# C++ Lambdas

---

## Lambda Expressions

* A _lambda expression_ (AKA "lambda") is an expression defining an anonymous function.
* Beginning with C++11, _lambda_ expressions are a standard language feature.

---

## Lambdas - Why?

* Why do we need another way of defining a function? 
    - Flexibility, convenience and expressiveness of syntax.
* Why do we say these are _anonymous_ functions?
    - They do not (inherently) have a name; they are defined only as an expression.
        + Although, of course, they can be stored in a "variable" -- which effectively gives them a name.
* Why would you want an _anonymous_ function?
    - "Use once and throw away"
        + Sometimes you don't need a specific function more than once.

---

## Syntax

Simple C++ lambda expressions are defined with the following syntax:

``` text
[=] ()  { std::cout << "I'm a lambda!"; }
(1) (2) (---------------3---------------)
```

(1): _capture clause_: lambdas can be allowed to "see" the local context from where they are written.  This clause sets rules/permissions for this "context capturing".

(2): _parameter list_: like regular functions, lambdas can receive parameters.

(3): _lambda body_: the body of the function
