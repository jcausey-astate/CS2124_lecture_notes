---

### Example: Two Versions of a Person

``` cpp
// Version 1 uses a C++ array   // Version 2 uses a dynamically-
// as a c-string for name:      // allocated c-string for name:
struct PersonV1{                struct PersonV2{
    int  age;                       int   age;
    char name[30];                  char* name;
};                              };
```

- What is the `sizeof()` each of these structures?
- Are there any logical differences in the interpretation of each?
    + What about implementation differences?

<!-- .slide: data-transition="slide", data-background="aliceblue" -->

---

<!-- .slide: data-transition="slide", data-background="aliceblue" -->

### Example: Two Versions of a Person

``` cpp
// Version 1 uses a C++ array   // Version 2 uses a dynamically-
// as a c-string for name:      // allocated c-string for name:
struct PersonV1{                struct PersonV2{
    int  age;                       int   age;
    char name[30];                  char* name;
};                              };
//-------------------------
IN MAIN: ---------------------------------
PersonV1 p1, p1copy;
PersonV2 p2, p2copy;

p1.age = 10;
strncpy(p1.name, "Adam", 30);

p2.age = 20;
p2.name = new char[30];
strncpy(p2.name, "Alice", 30);
```

---

<!-- .slide: data-transition="slide", data-background="aliceblue" -->

### Example: Two Versions of a Person

``` cpp
struct PersonV1{                struct PersonV2{
    int  age;                       int   age;
    char name[30];                  char* name;
};                              };
//-------------------------
IN MAIN: ---------------------------------
PersonV1 p1, p1copy; // p1 name is "Adam"
PersonV2 p2, p2copy; // p2 name is "Alice"
// [...]
p1copy = p1;
strncpy(p1copy.name, "Billy", 30);

p2copy = p2;
strncpy(p2copy.name, "Beth", 30);

cout << "p1: " << p1.name << " p1copy: " << p1copy.name << endl;
cout << "p2: " << p2.name << " p2copy: " << p2copy.name << endl;
//
// What will print out ???
//
```

<!-- .slide: data-transition="none", data-background="aliceblue" -->

---

<!-- .slide: data-transition="none", data-background="aliceblue" -->

### Example: Two Versions of a Person

``` cpp
struct PersonV1{                struct PersonV2{
    int  age;                       int   age;
    char name[30];                  char* name;
};                              };
//-------------------------
IN MAIN: ---------------------------------
PersonV1 p1, p1copy; // p1 name is "Adam"
PersonV2 p2, p2copy; // p2 name is "Alice"
// [...]
p1copy = p1;
strncpy(p1copy.name, "Billy", 30);

p2copy = p2;
strncpy(p2copy.name, "Beth", 30);

cout << "p1: " << p1.name << " p1copy: " << p1copy.name << endl;
cout << "p2: " << p2.name << " p2copy: " << p2copy.name << endl;
// Prints:   p1: Adam p1copy: Billy
//           p2: Beth p2copy: Beth
// WHAT WENT WRONG ???
```


---


### Two Versions of a Person: Conclusion

- The copy of `p1` to `p1copy` is fine, since the array in `PersonV1` is a statically-sized array.
    + The structure encapuslates the entire array, and bitwise copy is OK.
- The copy of `p2` to `p2copy` was __broken__, since `PersonV2` uses a _pointer_ to a dynamically-allocated c-string array.
    + The _pointer_ was copied, but not the _data_ or the _allocated space_!
        * This is referred to as a _shallow copy_.
        * We really want a _deep copy_ (which allocates more space and makes a true copy of the contents).

---