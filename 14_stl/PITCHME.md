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

### Who is STL?

![Stephan T. Lavavej](assets/images/STL/STL.jpg "Stephan T. Lavavej")

Stephan T. Lavavej is a Senior Software Development Engineer at Microsoft, maintaining Visual Studio's C++ Standard Library implementation. 

* In all seriousness, _the_ STL is overseen by the C++ Standards Committee

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
    - Random access iterators offer essentially the same functionality as pointers.
- `vector`s know their own size!


----

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

## `std::vector` Example
    
``` cpp
vector<string> v;                   // create vector

v.push_back("The number is 10");    // push some values
v.push_back("The number is 20");    // into it...
v.push_back("The number is 30");

cout << "Loop by index:" << endl;

for(int i=0; i < v.size(); i++){   // print values by            
   cout << v[i] << endl;            // indexing the
}                                   // vector
```

----

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

<small style="font-size: 90%;">

## `std::vector` Example 2
    
``` cpp
vector<string> v;                                  // create vector

v.push_back("The number is 10");                   // push some values
v.push_back("The number is 20");                   // into it...
v.push_back("The number is 30");

cout << "Loop by range:" << endl;

for(vector<string>::const_iterator it = v.begin(); // iterator
    it != v.end();                                 // runs from begin()
    ++it)                                          // to end()
{                                                  // and is 
   cout << *it << endl;                            // dereferenced to
}                                                  // print the value
```

</small>

----

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

## `std::vector` Example 2b
    
``` cpp
vector<string> v;                        // create vector

v.push_back("The number is 10");         // push some values
v.push_back("The number is 20");         // into it...
v.push_back("The number is 30");

cout << "Loop by range:" << endl;

for( auto item : v ){                   // each item in v
   cout << item << endl;                // print the item
}                                                  
```

----

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

## `std::vector` Example 3
    
``` cpp
auto v = vector<string>{3};             // reserve 3 items

int  n = 1;
for( auto& item : v){                   // ref to each item
    item = string{"The number is "}     // generate message
         + std::to_string(10 * n++);    // and store in item
}

cout << "Loop by range:" << endl;

for( auto item : v ){                   // copy of each item
   cout << item << endl;                // print the item
}                              
```

_`std::to_string()` is contained in `<string>`_

---

## Sequence Container: `std::deque`

STL’s `std::deque` (pronounced “deck”) is a _**d**ouble-**e**nded **que**ue_.

- Optimized for efficient insertion and removal at both the beginning and end.
    - `push_front()`, `push_back()`, `pop_front()`, `pop_back()`
- Also support random access iterators and `[]`.
- Elements are not guaranteed to be contiguous.

----

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

## `std::deque` Example

``` cpp
// the iterator constructor can be used to copy arrays:
int myints[] = {16,2,77,29};
std::deque<int> dq(myints, myints + sizeof(myints) / sizeof(int) );

std::cout << "The contents of the queue are:\n";
for(const auto& item : dq){
    static bool first = true;
    std::cout << (!first ? ", " : "") 
              << item 
              << (&item == &dq.back() ? "\n" : ""); 
    first = false;
}
```

---


## Sequence Container: `std::list`

STL’s `std::list` are sequence containers optimized for constant-time insert and delete anywhere in the list.

- May be iterated in either direction (but not random-accessed).
- Implemented as a doubly-linked list.


----


## `std::list` Example

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

``` cpp
// again, the iterator constructor can be used:
int myints[] = {75,23,65,42,13};
std::list<int> l (myints, myints+5);

std::cout << "l contains:";
for (std::list<int>::iterator it = l.begin(); 
    it != l.end(); 
    ++it)
{
    std::cout << (it != l.begin() ? ", " : "") << *it;
}
std::cout << '\n';
```

<!-- .slide: data-transition="none", data-background="aliceblue" -->

----


## `std::list` Example (C++11)

<!-- .slide: data-transition="none", data-background="aliceblue" -->

``` cpp
// again, the iterator constructor can be used:
int myints[] = {75,23,65,42,13};
std::list<int> l (myints, myints+5);

std::cout << "l contains: ";
for (const auto& item : l) {        // C++11!
    std::cout << (&item != &l.front() ? ", " : "") << item;
}
std::cout << '\n';
// 
// Three lines were saved by `auto`!
// 
```

---

## Associative Container: `std::map`

Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
- Keys and values may be of different types
- Keys may be any type that supports:
    - `operator<`
    - `operator==`

    -----        -------
    |Key| =====> |Value|
    -----        -------

----

## `std::map` Example

<!-- .slide: data-transition="none", data-background="aliceblue" -->

``` cpp
std::map <string, char> grade_list;

grade_list["John"]  = 'B';
grade_list["Alice"] = 'A';

if(grade_list.find("Tim") == grade_list.end()) {
    std::cout << "Tim is not in the map!" << std::endl;
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


----


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

----

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

## Algorithms

STL contains algorithms implemented as function templates.

- Designed to perform operations on containers.
- Requires algorithm header file
- Includes:
    
        binary_search     count
        find              find_if         
        for_each          max_element
        min_element       partition
        random_shuffle    rotate
        sort              stable_partition
        stable_sort       ... and many more 

---

## C++ Standard Smart Pointers

Requires the `<memory>` header.

* `std::unique_ptr` - Takes singular (non-shared) ownership of a resource.
* `std::shared_ptr` - Assumes shared ownership of a resource.
* `std::weak_ptr` - A non-owning pointer that can be converted to a `shared_ptr` when access to the resource is required.



