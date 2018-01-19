# CS2124
## Dynamic Memory Allocation 
### (Chapter 9.8 {pg 518})

---

## Dynamic Memory Allocation
* We can allocate storage for data while the program is running.
* `new` operator
* Returns the _address of the first byte_ of the new storage location.

__Example:__

``` cpp
double* dptr;
dptr = new double;
```

---

## Dynamic Memory Allocation
* Can allocate single variables or arrays.

__Array example:__

``` cpp
const int SIZE   = 25;
double* arrayPtr = new double[SIZE];
```

* Also returns the address of the first byte allocated.
* Pointers to arrays can be used just like regular arrays ...
*  ... or with pointer notation.

---

## Pointer Arithmetic
* Pointers are just memory addresses.
* The type associated is only there to tell the computer how large each value is (in bytes).
* You can add or subtract from a pointer to “move it” to a different logical value in memory.

__Example:__

``` cpp
double* aPtr = new double[5];
aPtr += 2;   // aPtr now points to the 
             // 3rd element in the array.
```

---

## What if something goes wrong?
* An exception is thrown and the program will terminate if there is not enough free memory to complete the request.

* Or, you can use the (`std::nothrow`) version:

``` cpp
int *xPtr = new(std::nothrow) int;
```

In this case, test that the address returned isn’t nullptr (nullptr will indicate failure). 

__Ex:__  `if(xPtr == nullptr)   // failed`    


---

## Releasing Dynamic Memory

___“You bought it… you deal with it!”___

* Any memory allocated with new must eventually be released back to the system.
* You are responsible for doing this (the system will not do it for you*)
    * *except when the program ends
* The `delete` operator releases memory:

``` cpp
delete dPtr;    // delete a variable
delete [] aPtr; // delete an array
```

---

## Final Notes
* If you "`new`" it, you "`delete`" it!
* `new` and `delete` operations may or may not be in the same scope
    - _This is a feature_:  It is one way to make data survive going out of scope.
* Failure to `delete` == memory leak!
* This is what destructors are good at!
    - Objects that do "`new`" operations will require a destructor.

