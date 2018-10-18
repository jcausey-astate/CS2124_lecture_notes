---?image=assets/images/STL/circle_template.jpg


#   STL
##  The C++ <br> Standard Template Library
### (Ch. 16.5)


---


## The Standard Template Library

- What is STL?
- Why use STL?
- Overview of STL Features and Concepts
- Containers
- Iterators
- Algorithms
- References for more information on STL


---

##  What is STL?

> "The Standard Template Library provides a set of well structured
> generic C++ components that work together in a seamless way."
>
> \- Alexander Stepanov & Meng Lee,
>    _The Standard Template Library_

- Designed to provide a common, familiar interface.
- Designed to meet specific performance/complexity goals.
- Keeps programmers from "re-inventing the wheel".

---

##  Why Use STL?

- Reuse: "Write less, do more"
    - STL hides complex, error-prone details.
    - Allows you to focus on the problem.
    - Type-safe compatibility between components.
- Flexibility
    - Iterators decouple algorithms from containers.
    - Unanticipated combinations easily supported.
- Efficiency
    - Templates avoid virtual function overhead.
    - Strict attention to time and/or space complexity of algorithms.

---

## STL Features and Concepts

- Containers
    - Sequence: `vector`, `list`, `deque`
    - Associative: `set`, `multiset`, `map`, `multimap`
- Adapters: `stack`, `queue`, `priority_queue`
- Iterators
    - Used to access elements in containers
    - Input, output, forward, bidirectional, & random access
    - Each container declares a trait for the type of iterator it provides
- Generic Algorithms
    - Mutating, non-mutating, sorting, numeric

---

## STL Containers

- STL Containers are _Abstract Data Types_ (ADTs)
- All containers are parameterized by the type(s) they contain.
- All declare traits :
    - e.g. `iterator`, `const_iterator`, `value_type`, etc.

---


## Container Types

- Sequence
    - Provide efficient linear access to data
    - Element order is not related to value
    - Think arrays and linked lists
- Associative
    - Provide efficient access to data stored as a key/value pair
    - Keys can be ordered by `operator<`
    - Implemented as balanced binary trees
- Adapters
    - Provide alternative ways to access sequence and associative containers
    - e.g. `stack`, `queue`, `priority_queue`


---


## Sequence Container: `std::vector`

STL’s `std::vector` is essentially a dynamic array.

- Grows and shrinks at the end.
- Supports `push_back()` and `pop_back()` sequential (end) access.
- Optimized for random access using array index operator. (`[]`)
- Supports random access iterators
    - An _iterator_ is an object used to access individual items in a container, or to move (i.e. "iterate") through the container.
- `vector`s know their own size!


+++

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

## `std::vector` Example

``` cpp
using std::vector;
using std::string;
// [...]
vector<string> v;                   // create vector

v.push_back("The number is 10");    // push some values
v.push_back("The number is 20");    // into it...
v.push_back("The number is 30");

cout << "Loop by index:" << endl;

for(vector<string>::size_type i=0;  // size type is unsigned
    i < v.size();                   // vector knows its size!
    i++){                           // print values by
   cout << v[i] << endl;            // indexing the
}                                   // vector like an array
```

+++

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

<small style="font-size: 90%;">

## `std::vector` Example 2

``` cpp
std::vector<std::string> v;         // create vector

v.push_back("The number is 10");    // push some values
v.push_back("The number is 20");    // into it...
v.push_back("The number is 30");

cout << "Loop by range:" << endl;

for(auto it = v.begin();            // iterator
    it != v.end();                  // runs from begin()
    ++it)                           // to end(), one at a time
{                                   // and is
   cout << *it << endl;             // dereferenced to
}                                   // print the value
```

</small>

* Think of an iterator as an arrow pointing to a value in the container.
* The _dereference operator_ (`*`) is used to "follow the arrow" to get the value an iterator is pointing to.

+++

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

## `std::vector` Example 2b

``` cpp
std::vector<std::string> v;         // create vector

v.push_back("The number is 10");    // push some values
v.push_back("The number is 20");    // into it...
v.push_back("The number is 30");

cout << "Loop by range:" << endl;

for( auto item : v ){               // for each item in v
   cout << item << endl;            // print the item
}
```

+++

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

## `std::vector` Example 3

``` cpp
auto v = std::vector<std::string>{3};    // pre-size to 3

int  n = 1;
for( auto& item : v){                    // each item (by ref.)
    item = std::string{"The number is "} // generate message
         + std::to_string(10 * n++);     // and store in item
}

cout << "Loop by range:" << endl;

for( auto item : v ){                    // for each item
   cout << item << endl;                 // print the item
}
```

<emph>`std::to_string()` is contained in `<std::string>`</emph>


---

## Iterators

Iterators are a generalization of pointers.

- Used to access information in containers, regardless of the internal layout
- Four types:
    - Forward (uses `++`)
    - Bidirectional (uses `++` and `--`)
    - Random-access (behave like normal pointers)
    - Input (can be used with input streams)
    - Output (can be used with output streams)


+++


## Iterator Example

<!-- .slide: data-transition="none", data-background="aliceblue" -->

``` cpp
std::vector<int> scores{3};

scores[0] = 88;
scores[1] = 92;
scores[2] = 76;

for(auto it = scores.begin(); it != grade_list.end(); it++){
    std::cout << *it << '\t';
}
std::cout << '\n';
```

**`it`**'s type is `std::vector<int>::iterator`

---

## Sequence Container: `std::deque`

STL’s `std::deque` (pronounced “deck”) is a _**d**ouble-**e**nded **que**ue_.

- Optimized for efficient insertion and removal at both the beginning and end.
    - `push_front()`, `push_back()`, `pop_front()`, `pop_back()`
- Also support random access iterators and `[]`.
- Elements are not guaranteed to be contiguous.

+++

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

## `std::deque` Example

``` cpp
std::deque<int> dq{16,2,77,29};

std::cout << "The contents of the queue are:\n";
for(const auto& item : dq){
    std::cout << (&item != &dq.front() ? ", " : "") 
              << item;
}
std::cout << '\n';
```

---

## Sequence Container: `std::list`

STL’s `std::list` are sequence containers optimized for constant-time insert and delete anywhere in the list.

- May be iterated in either direction (but not random-accessed).
- Implemented as a doubly-linked list.


+++


## `std::list` Example

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

``` cpp
std::list<int> l{75,23,65,42,13};

std::cout << "l contains:";
for (auto it = l.begin(); it != l.end(); ++it)
{
    std::cout << (it != l.begin() ? ", " : "") << *it;
}
std::cout << '\n';
```

<!-- .slide: data-transition="none", data-background="aliceblue" -->

+++

## `std::list` Example (>=C++11)

<!-- .slide: data-transition="none", data-background="aliceblue" -->

``` cpp
std::list<int> l{75,23,65,42,13};

std::cout << "l contains: ";
for (const auto& item : l) {        // range-based for
    std::cout << (&item != &l.front() ? ", " : "") << item;
}
std::cout << '\n';
```

---

## Associative Container: `std::map`

Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
- Keys and values may be of different types
- Keys may be any type that supports:
    - `operator<`
    - `operator==`

<pre>
    -----        -------
    |Key| =====> |Value|
    -----        -------
</pre>

+++

## `std::map` Example

<!-- .slide: data-transition="none", data-background="aliceblue" -->

``` cpp
std::map <std::string, char> grade_list;

grade_list["John"]  = 'B';
grade_list["Alice"] = 'A';

for(auto name : {"Alice", "Tim", "John", "Sarah"}){
    if(grade_list.find(name) != grade_list.end()) {
        std::cout << name << " : " 
                  << grade_list[name] << '\n';
    }
    else{
        std::cout << name << " is not in the map.\n";
    }
}
```

---

## Associative Container: `std::unordered_map`

Unordered Maps are associative containers that store elements formed by a combination of a key value and a mapped value, but with no implied order.  The underlying data structure is a _hash table_.  These are often more performant than the ordered `std::map`.
- Keys and values may be of different types

<pre>
    -----        -------
    |Key| =====> |Value|
    -----        -------
</pre>

+++

## `std::unordered_map` Example

<!-- .slide: data-transition="none", data-background="aliceblue" -->

``` cpp
std::unordered_map <std::string, char> grade_list;

grade_list["John"]  = 'B';
grade_list["Alice"] = 'A';

for(auto name : {"Alice", "Tim", "John", "Sarah"}){
    if(grade_list.find(name) != grade_list.end()) {
        std::cout << name << " : " 
                  << grade_list[name] << '\n';
    }
    else{
        std::cout << name << " is not in the map.\n";
    }
}
```

---

## Iterators

Iterators are a generalization of pointers.

- Used to access information in containers, regardless of the internal layout
- Four types:
    - Forward (uses `++`)
    - Bidirectional (uses `++` and `--`)
    - Random-access (behave like normal pointers)
    - Input (can be used with input streams)
    - Output (can be used with output streams)


+++


## Iterator Example

<!-- .slide: data-transition="none", data-background="aliceblue" -->

``` cpp
std::map <std::string, char> grade_list;

grade_list["John"]  = 'B';
grade_list["Alice"] = 'A';
grade_list["Eve"]   = 'C';

std::map<string, char>::iterator it = grade_list.begin();
for(; it != grade_list.end(); it++){
    std::cout << it->first  << ": "
              << it->second << std::endl;
}
```

+++

## Don't Forget Range-Based Loops!

<!-- .slide: data-transition="none", data-background="aliceblue" -->

```cpp
std::map <std::string, char> grade_list;

grade_list["John"]  = 'B';
grade_list["Alice"] = 'A';
grade_list["Eve"]   = 'C';

for(const auto& kv : grade_list){
    std::cout << kv.first  << ": "
              << kv.second << std::endl;
}
```

---

## C++ Standard Smart Pointers

Requires the `<memory>` header.

* `std::unique_ptr` - Takes singular (non-shared) ownership of a resource.
* `std::shared_ptr` - Assumes shared ownership of a resource.
* `std::weak_ptr` - A non-owning pointer that can be converted to a `shared_ptr` when access to the resource is required.

---

## Unique Pointer

The C++ `std::unique_ptr` is defined in `<memory>`.  It represents a smart pointer that assumes singular ownership of a resource.

**How it works:**

* During construction, assume ownership of the resource.
* Expose the operations expected for a pointer.
    * dereference, arrow, and (maybe) array-index; maybe others...
* During destruction, de-allocate the managed resource.

---

## Shared Pointer

Implemented as a _reference counting_ pointer, meaning that the resource will not be deleted as long as at least one reference to it (via a `shared_ptr`) still exists.

**How it works:**

* During construction, assume ownership of the resource.
    * If this is the first instance, set reference count to 1.
    * If this is a copy, increment the reference count.
* Expose the operations expected for a pointer.
    * dereference, arrow, and (maybe) array-index; maybe others...
* During destruction, decrement the reference count.
    * If the reference count has gone to 0, delete the managed resource.

---

## Algorithms

STL contains algorithms implemented as function templates.

- Designed to perform operations on containers.
- Requires algorithm header file  `#include <algorithm>`
- Includes:

<pre>
    accumulate()      max()           partition()
    binary_search()   max_element()   stable_partition()
    copy()            min()           for_each()
    count()           min_element()   find_if()
    fill()            reverse()       random_shuffle()
    find()            sort()          rotate()
    is_sorted()       swap()          stable_sort()

               ... and many more ...
</pre>

---

## Algorithms Overview

* Algorithms use _iterators_ for operating on _ranges_ of values in a container.
* Most will take (at least) a "first" and "last" iterator:

![Sub-range in array](https://cdn.rawgit.com/jcausey-astate/CS2114_lecture_notes/master/assets/images/shared/range_iterators_to_subrange.svg)

+++

## Usually use `begin` and `end`

* If you want the entire container, then<br>`first = container.begin()` and `last = container.end()`.

![Range based iterators](https://cdn.rawgit.com/jcausey-astate/CS2114_lecture_notes/master/assets/images/shared/range_iterators_in_array.svg)

---

Container-wise algorithms:

<pre>
    accumulate()        is_sorted()
    binary_search()     max_element()
    copy()              min_element()
    count()             random_shuffle()
    fill()              reverse()
    find()              rotate()
    find_if()           [stable_]partition()
    for_each()          [stable_]sort()
</pre>

Element-wise algorithms:

<pre>
    max()               swap()
    min()
</pre>

---

### `accumulate(first, last, start_value)`
<br><br>


Returns the sum of the range [`first`,`last`), starting from the initial value `start_value`.

```cpp
std::vector<int> v{5,3,4,2,9,2,6,3,8};

int sum = std::accumulate(v.begin(), v.end(), 0);
std::cout << sum << '\n';
// 42
```

---

### `binary_search(first, last, target)`
<br><br>


Fast search in range for `target`; requires range to be sorted.  Returns `true` if the target is found, `false` otherwise.

```cpp
std::vector<int> v{0,2,4,6,8,10,12,14,16,18};

bool found = std::binary_search(v.begin(), v.end(), 10);
if( found ){
    std::cout << "Found 10.\n";
}
// Found 10
found = std::binary_search(v.begin(), v.end(), 9);
if( found ){
    std::cout << "Found 9.\n";
}
// (9 was not found, no output)
```

---

### `copy(src_first, src_last, dst_first)`
<br><br>


Copies range [`src_first`,`src_last`) to destination starting at `dst_first`.

```cpp
std::vector<int> v1{5,3,4,2,9,2,6,3,8};
std::vector<int> v2;
v2.resize(v1.size());  // Destination must be pre-allocated!

std::copy(v1.begin(), v1.end(), v2.begin());

for( auto item : v2 ){
    std::cout << item << '\t';
}
// 5  3  4  2  9  2  6  3  8
```

Note that invalid arguments cause _**undefined behavior**_.

---

### `count(first, last, target)`
<br><br>


Count the number of times `target` appears in the range.

```cpp
std::vector<int> v{5,2,4,2,9,2,6,3,8};

int number_of_twos = std::count(v.begin(), v.end(), 2);

std::cout << "There are " << number_of_twos << " twos.\n";
// There are 3 twos.
```

---

### `fill(first, last, value)`
<br><br>


Fill a range with a single value.

```cpp
std::vector<int> v;
v.resize(10);

std::fill(v.begin(), v.end(), -1);

for( auto item : v ){
    std::cout << item << '\t';
}
// -1  -1  -1  -1  -1  -1  -1  -1  -1  -1
```

---

### `find(first, last, target)`
<br><br>


Find "target" element; returns an iterator to the target or `last` if not found.

```cpp
std::vector<int> v{5,3,4,2,9,2,6,3,8};

std::vector<int>::iterator it;
it = std::find(v.begin(), v.end(), 9);

if(it != v.end()){
    std::cout << "Found " << (*it) << '\n';
}
// Found 9
```

---

### `is_sorted(first, last)`
<br><br>


Returns `true` if the range is sorted; `false` otherwise.

```cpp
std::vector<int> v1{5,3,4,2,9,2,6,3,8};
std::vector<int> v2{0,1,2,3,4,5,6,7,8,9};

if( std::is_sorted(v1.begin(), v1.end())){
    std::cout << "v1 is sorted\n";
}

if( std::is_sorted(v2.begin(), v2.end())){
    std::cout << "v2 is sorted\n";
}
// v2 is sorted
```

---

### `max_element(first, last)`
<br><br>


Returns an iterator to the (first) maximum element.

```cpp
std::vector<int> v{5,3,4,2,9,2,6,3,8};

std::vector<int>::iterator it;
it = std::max_element(v.begin(), v.end());

std::cout << (*it) << '\n';
// 9
```

---

### `min_element(first, last)`
<br><br>


Returns an iterator to the (first) minimum element.

```cpp
std::vector<int> v{5,3,4,2,9,2,6,3,8};

std::vector<int>::iterator it;
it = std::min_element(v.begin(), v.end());

std::cout << (*it) << '\n';
// 2
```

---

### `reverse(first, last)`
<br><br>


Reverses the order of values in the range.

```cpp
std::vector<int> v{0,1,2,3,4,5,6,7,8,9};

std::reverse(v.begin(), v.end());

for( auto item : v ){
    std::cout << item << '\t';
}
// 9  8  7  6  5  4  3  2  1  0
```

---

### `sort(first, last)`
<br><br>


Sorts a container in-place.

```cpp
std::vector<int> v{5,2,4,9,7,1,6,3,0,8};

std::sort(v.begin(), v.end());

for( auto item : v ){
    std::cout << item << '\t';
}
// 0  1  2  3  4  5  6  7  8  9
```

---

### `rotate(first, handle, last)`
<br><br>


Rotates the `handle` to the front of the range.


```cpp
std::vector<int> v{0,1,2,3,4,5,6,7,8,9};

std::rotate(v.begin(), v.begin() + 3, v.end());

for( auto item : v ){
    std::cout << item << '\t';
}
// 3  4  5  6  7  8  9  0  1  2
```

---

### `partition(first, last, predicate)`
<br><br>


Partitions so that elments matching the predicate are first, returns the split point.

```cpp
bool is_even(int x){ return x % 2 == 0; }
std::vector<int> v{1,2,3,4,5,6,7,8,9,10};

auto split = std::partition(v.begin(), v.end(), is_even);

for( auto item : v ){
    std::cout << item << '\t';
}
// 2  4  6  8  10  1  3  5  7  9
for(auto it = v.begin(); it != split; ++it){
    std::cout << *it << '\t';
}
// 2  4  6  8  10
```

---

### `max(value1, value2)`
<br><br>


Returns the larger of the two values.

```cpp
int a = 8;
int b = 12;

std::cout << std::max(a, b) << '\n';
// 12
```

---

### `min(value1, value2)`
<br><br>


Returns the smaller of the two values.

```cpp
int a = 8;
int b = 12;

std::cout << std::min(a, b) << '\n';
// 8
```

---

### `swap(value1, value2)`
<br><br>


Swaps the values stored in the arguments.

```cpp
int a = 8;
int b = 12;

std::swap(a, b);
std::cout << "a: " << a << " b: " << b << '\n';
// a: 12 b: 8
```

