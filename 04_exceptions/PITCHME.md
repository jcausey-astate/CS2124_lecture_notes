# Exceptions
# 
## (Ch 16)

---

## Exceptions
* Used to communicate that something unexpected has occurred.
* Allows the programmer to deal with unexpected situations in a controlled manner.
* May be as simple or as complex as desired (depending on usage in the program)
* In C++, _any_ data value can be used as an exception!

---

## Key Words

__*`throw`*__ - Used to generate an exception and “throw” it up the _call stack_.

__*`try`*__ – Used to enclose a block of code in which an exception _might_ occur (allowing the programmer to handle it if it does).

__*`catch`*__ – Used to detect and handle a specific type of exception, if it _actually occurred_ during execution of a `try` block.

---

## Flow of Control

When something unexpected happens, a function may choose to throw an exception.  
* At this point, execution leaves the function immediately!
* Exception moved up the call stack until a `try` with a matching  `catch` clause is found.
    - Execution resumes with the first line of the `catch` block (if found).
* If not caught, the exception eventually makes it up to the OS, which will shut down the process.

---

<!-- .slide: data-transition="linear", data-background="aliceblue" -->

__Example__

``` cpp
// function that *may* throw an exception
int totalDays(int days, int weeks){
    if((days < 0) || (days > 7)){
        // value being thrown is a C-string:
        throw "Invalid value for days.";
    }
    return 7 * weeks + days;
}
```

----

<!-- .slide: data-transition="none", data-background="aliceblue" -->

__Example__

``` cpp
int main(){
    int days, weeks;
    // assume days, weeks gets some value
    // here (from user, etc).
    try {  
        auto totDays = totalDays(days, weeks);
        cout << "Total days: " << totDays;
    }
    catch (const char* msg) {
        cout << "Error: " << msg;
    }
    return 0;
}
```

---

## What Happens?
* `try` block is entered.  `totalDays()` function is called.
* If 1<sup>st</sup> parameter is between 0 and 7, calculate the number of days and return as usual (no exception).
* If 1st parameter is out of range, exception of type `const char*` is thrown: Execution leaves the function immediately.
* `try` block execution is halted, execution jumps to first `catch` block, looking for a <br />
`catch(const char*)` <br />
* Since the type matches, execution resumes in the `catch` block.

---

## Notes
* Many `catch` blocks may follow a single `try` (but there must be at least one).
* You cannot `catch` without `try`, or `try` without `catch`.
* `catch` blocks are scanned until one matches the type of the exception thrown.
* `catch` blocks may or may not have formal parameter name (depending on whether the exception value itself will be needed inside the block).

---

## Missed Exceptions
* Failure to catch an exception just means it continues “flying” up the call stack. 
* If it gets all the way out of `main()` without being caught, the program will be terminated by the OS.
* It is possible to define a “catch-all” `catch` block (although it is often considered sloppy to do so):<br />
`catch( ... )` <br />  
    * If you define a “catch-all”, it should be the last `catch` in the chain.

---

## Exception Classes/Objects
* Any type may be thrown.  Even custom objects.
* We can define objects specifically for this purpose.
* _Exception classes_ are useful to put a meaningful name on the type (so that `catch` blocks are easy to understand).

**Example**

`catch( NullPointerException )` <br />  
is better than <br />   
`catch( int )`

---

## Exception Classes

* Don’t necessarily need members
    - Unless they do: if the added functionality is useful, add it!

**Example**

``` cpp
class NullPointerException{ };  // empty
```

Or:

``` cpp
class NullPointerException{
    public:
        string msg;            // with attribute
};
```

---

## Standard Exceptions
The C++ Standard Library defines an `exception` base class in the `<exception>` header.

* Useful (later) to make our own exceptions with nice common behaviors.

``` cpp
#include<exception>
    using std::exception;

class NullPointerException : public exception{
    public:
        virtual const char* what()const {
            return “A null pointer was encountered.”;
        }
};
```

----

## Standard Exceptions

Also, _Polymorphism_!

``` cpp
try{
    [...] 
}
catch(exception& e){   
    // catches _any_ standard exception!
    cout << e.what()  << endl;
}
```

---

## Pre-Defined Standard Exceptions

The `<stdexcept>` header defines some standard exception classes that are ready-to-use.  They are divided into two sets (names are self-explanatory):

**Logic errors**
``` asciidoc
logic_error      
domain_error     
invalid_argument 
length_error
out_of_range
```

**Runtime errors**

``` asciidoc
runtime_error   
range_error     
overflow_error  
underflow_error 
```

---

## Other Useful Standard Library Exceptions

``` cpp
    exception
    bad_alloc
    bad_cast
    bad_exception
    bad_typeid
    ios_base::failure
```