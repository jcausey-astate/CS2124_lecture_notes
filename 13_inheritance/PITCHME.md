# Inheritance
## (Ch 15)

---

## Inheritance

Establishes an "_is-a_" relationship:

* A flower _is a_ plant.
* A lager _is a_ beer.
* An ale _is a_ beer.
* A truck _is a_ vehicle.
    * A dump truck _is a_ truck.
* A mammal _is a(n)_ animal.
    * A dog _is a_ mammal.
        * A poodle _is a_ dog.
 
_... Infinite examples:  The real world works this way!_

---

## Terminology and Notation

* _Base class_ (or _parent_): the more general class… the "starting point".
* _Derived class_ (or _child_): more specialized, derived from base class.
* Notation:

![Base and derived class headers.](assets/images/Inheritance/base_and_derived_class_headers.png )


---

## How "is-a" Works

* Derived class object "is a(n)" object of the base class.
    - Has all characteristics of base class!
        + All members defined in base class.
        + Plus all members defined in derived class.
* Derived class objects can "use" (access):
    - All `public` or `protected` members of base class.
    - All members of derived class.

---

## Wait... `protected`?
* `protected` : _access specifier_, similar to `private`
    - Except:  `protected` members _can_ be accessed by derived classes!
    - Useful when you know you are writing a base class.
* `private` data from base class is part of derived class, but _cannot be accessed_.

---

## Class Access Specifiers

* You may inherit with a selected level of access:
    - `public`
        + True "is-a" relationship.  
    - `protected`
        + `public` items from base class become `protected` in derived class.
    - `private`
        + `public` and `protected` items from base class become `private` in derived class.
        + Derived class object _cannot_ be treated as an object of the base class.

---

## Class Access Specifiers

![Diagram of effect of access specifiers.](https://cdn.rawgit.com/jcausey-astate/CS2124_lecture_notes/master/assets/images/Inheritance/Inheritance_Access_Levels.svg)

---

## Building and Tearing-Down

* Base class must be constructed before derived class.
* Derived class must be destructed before the base class.
* Derived class may pass arguments to base class constructor:
```cpp
    Square::Square(int s) : Rectangle(s, s)
```
