---
title: "03_Arrays"
date: 2020-10-02T12:30:15-05:00
draft: false
---

## Arrays
### (Ch. 7)

---

## The C++ Array

_Arrays_ allow programmers to store multiple related values of the same type.

* Values are stored sequentially in memory.
* Declaration syntax: <br />
_`type`_ _`arrayname`_`[` _`size_declarator`_ `]`;

**Example Declarations**
``` cpp
int    a[100]; // Declares an array of 100 integers.
double b[50];  // Declares an array of 50 doubles.
```

---

## Array Memory Layout

The declaration:

``` cpp
int tests[5];
```

allocates the following memory:

![Array elements are contiguous boxes in memory.](../images/shared/integer_array_no_indices.svg)

* Arrays are a _reference type_.
    - The array variable does not refer to the array as a whole, only to the location of the first element.

---

## Terminology

In the declaration: <br />
`int tests[5];`

* `int` is the **data type** of _all_ elements in the array.
* `tests` is the **name** of the array.
* `5` (in `[5]`) is the **size declarator**.  It specifies the _number of elements_.
    - The storage size of the array is <br /> _`NumberOfElements * SizeOfEachElement`_.
    - The size declarator **must** be either a _literal_ or _constant_.

---

## Size Declarators

Named constants are often used as size declarators.

``` cpp
const int CLASS_SIZE = 5;
int       tests[CLASS_SIZE];
```

* Makes maintenance easier if size needs to change.
* Avoids creating "_magic numbers_".
    - _magic numbers_ are literal numeric values that appear repeatedly for reasons that are non-obvious by the context.

---

## Indexes and Elements

Each individual data item in an array is referred to as an _array element_.

![Array elements are contiguous boxes in memory.](../images/shared/integer_array_no_indices.svg)

Elements are identified by an integer _index_, starting from 0.

![Array elements are identified by integer indices.](../images/shared/integer_array_with_indices.svg)

---

## Initial Values

Array elements start out _uninitialized_.

![Array elements are uninitialized.](../images/shared/integer_array_uninitialized.svg)

Use the element's _index number_ and _array index syntax_ to access individual elements:

``` cpp
tests[0] = 88;
```

![Array with first value initialized.](../images/shared/integer_array_first_element_initialized.svg)

---

**Example**

``` cpp
tests[0] = 88;
tests[1] = 92;
tests[2] = 76;
tests[3] = 85;
tests[4] = 63;
```

Produces:

![Array with values.](../images/shared/integer_array_with_values.svg)

---

## Generate Indices with a Loop

The array index may be specified by a _literal_, _variable_, or _integer expression_.

``` cpp
// Assume "tests" has been initialized as shown previously...

// Display tests from tests array to standard output:
for(int i = 0; i < 5; i++){
    std::cout << tests[i] << "\n";
}
```

---

**Example: Initialize Array with Loop**

``` cpp
int a[100];                     // Declare array of 100 integers.
for(int i = 0; i < 100; i++){   // Initialize all elements to 0
    a[i] = 0;
}
```

---

### Details: Declaration and Initialization

* Size declarators **must** be a _literal_ or _constant_.
    - You **cannot** use a variable as a size declarator.
        + No, you really can't!
            + _**Seriously, you can't.**_
* C++ provides **no bounds checking** for indices!
    - You must be careful not to access out-of-bounds.
    - Never trust a user-entered value for calculating an index!  Check it first.

---

## Array Initializer Syntax

Because it makes tests questions easy...

``` cpp
int tests[5] = { 88, 92, 76, 85, 63 };
```

Creates the same array we saw earlier:

![Array with values.](../images/shared/integer_array_with_values.svg)

---

## Array Initializer Syntax

``` cpp
int tests[] = { 88, 92, 76, 85, 63 };
```

* Size declarator is _optional_ here, since the compiler can count.
* This is _only_ useful if you know all of the values that will be stored at the time you are writing the program.
    - That is rarely the case.
* So, loops it is!

---

## Uniform Initialization Syntax

``` cpp
int tests[] { 88, 92, 76, 85, 63 };
```

* Like array initializer syntax, the size declarator is _optional_ here.
* The only difference is the lack of the `=` operator.

---

## Array Assignment

You **cannot** directly _assign_ one array to another:

``` cpp
copy_of_tests = tests;  // WILL NOT WORK!!!
```

**Correct way** - Assign element-by-element:

``` cpp
for(int i = 0; i < 5; i++){
    copy_of_tests[i] = tests[i];
}
```

---

## Arrays as Parameters

* Arrays may be passed to functions:
```cpp
void print_tests(int tests[], int size){
    for(int i = 0; i < size; i++){
        std::cout << tests[i] << "\n";
    }
}
```
* Notice that the array's **size must also be passed**.
    - Arrays do not "know their own size". 
* Notice the empty size declarator in the formal parameter.
    - First dimension does not require (or allow) a size declarator in a formal parameter declaration.
* Arrays are **always** passed _by reference_.

---

## 1-D Arrays Key Points Summary

* Size declarator must be a literal or constant.
* C++ provides no bounds-checking for indices.
* Array elements start out uninitialized.
* Arrays cannot be directly assigned.
* Arrays are always passed by reference to functions.
* Arrays do not "know" their own size.

---

## Parallel &<br />Multi-Dimensional<br/>Arrays

---

## Parallel Arrays

* _**Parallel Arrays**_:  Two or more arrays containing related data such that the elements at corresponding indexes are related.
    - All elements at index `i` the parallel arrays make up a single _record_ `i`.

**Example**
``` cpp
const int   N_CONTESTANTS = 5;
std::string names[N_CONTESTANTS];
int         votes[N_CONTESTANTS];
// Each contestant has a name and a vote count.
for(int i = 0; i < N_CONTESTANTS; i++){
    std::cout << "Contestant " << (i+1) << " name: ";
    std::cin  >> names[i];
    std::cout << "# of votes for " << names[i] << ": ";
    std::cin  >> votes[i];
}
```


---

## Parallel Arrays

* Since the parallel arrays are separate, they may be of mixed type.
* Any operation that updates one of the parallel arrays must update all others to maintain the parallel property.
* All arrays must be passed to functions separately (although one "size" parameter is usually sufficient).

---

## 2-Dimensional Arrays

C++ allows multiple dimensions for arrays.  This is achieved by simply adding additional size declarators:

``` cpp
int votes[5][3]; // create array with 5 rows and 3 columns
```

* Notice that _two sets_ of square brackets are needed for a 2-D array.
* Same rules apply for size declarators here.  (constants or literals only)

---

## Layout (Logical)

``` cpp
int votes[5][3]; // create array with 5 rows and 3 columns
```

![2-D Array of integers.](../images/shared/2D_array_with_indices.svg)

---

## Layout (Physical)

``` cpp
int votes[5][3]; // create array with 5 rows and 3 columns
```
In reality, all physical memory is 1-dimensional.

Rows are sequential!

![2-D Array of integers.](../images/shared/2D_array_with_indices_physical_layout.svg)

---

## Using Constants for Size

Avoid "magic numbers" by using named constants for size declarators:

``` cpp
const int N_CONTESTANTS = 5; // # of contestants
const int N_DAYS        = 3; // contest length

// [...]

int votes[N_CONTESTANTS][N_DAYS]; // table of contest votes
```
<small>It can sometimes be useful to allow these constants to be _global_ in some cases (as we will see shortly).</small>


---

## Working with 2-D Arrays

Almost all operations on 2-D arrays will require _nested loops_.

_Think "for each row, for each column, do some operation"._

``` cpp
// Initialize "votes" array:
for(int i = 0; i < N_CONTESTANTS; i++){
    for(int j = 0; j < N_DAYS; j++){
        votes[i][j] = 0;
    }
}
```

---

## 2-D Arrays as Formal Parameters

Because of the reality of the physical (1-D) layout of the array, C++ requires that you specify a _size declarator_ for **every dimension except the first** when listing arrays in formal parameter lists.

``` cpp
void print_matrix( int matrix[][4], int n_rows ){
    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < 4; j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
```
The number of _rows_ can still be a parameter, allowing it to vary.


---

## 2-D Arrays as Formal Parameters

Again, to avoid "magic numbers", we often set up **global constants** for the sizes of each dimension after the first:

``` cpp
const int N_COLS = 4; // GLOBAL constant, defined at top.

// [ ... ]

void print_matrix( int matrix[][N_COLS], int n_rows ){
    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < N_COLS; j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
```

---

## Arrays of Higher Dimension

There is no (practical) limit on the number of dimensions an array can have.

Higher-dimensional arrays **require substantial memory resources**.

**Example: 3-D Array**

``` cpp
const int ROWS  = 8;
const int COLS  = 8;
const int MOVES = 100; // Number of replay steps
// [...]
int game_board_over_time[MOVES][ROWS][COLS];
```

Requires `8 * 8 * 100 * sizeof(int) => 25600` bytes (25 KB). 

---

## Arrays of Higher Dimension

Operations just require more nested loops (one for each dimension):

``` cpp
for(int move = 0; move < MOVES; move++){
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLUMNS; c++){
            cout << game_board_over_time[move][r][c]
                 << "\t";
        }
        cout << "\n";
    }
}
```
