## `static` Members   
## and Function Pointers


---

## Instance and Static Members

* Normal members of a class are called _instance members_. Each object has its own copy.
* Members may also be declared _`static`_. 
    - Static Attributes: Only one memory location is allocated for the class; all objects instantiated from the class share the storage (shared data).
    - Static Methods: Can be called without first instantiating an object of the class; can access static attributes.
* Use the `static` type modifier

---

## Pointers to Functions

* Function code is stored in memory just like all other data.
* The compiler must know _where_ the function is stored in order to call it...
    - We can create a pointer to anything that has an address!

**Syntax:**

_`RetType`_` (* `_`ptrName`_`)( `_`paramList`_`);`

<small>This would declare a pointer `ptrName` to a function whose prototype parameter list matches `paramList` and whose return type is `RetType`.  
For example, a pointer capable of pointing to the `cmath` `pow()` function might look like: </small>

``` cpp
double (*powPtr)(double, double);
```


---

__Example__

``` cpp
// Create a pointer to the built-in "pow()" function:
double (*powPtr)(double, double) = &pow;

// Use the pointer to compute an exponent:
double fourCubed = powPtr(4, 3);
std::cout << "Four cubed is: " << fourCubed << "\n";
```

Prints: &nbsp;&nbsp;&nbsp;&nbsp; `Four cubed is: 64`
