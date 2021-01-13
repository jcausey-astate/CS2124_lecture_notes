---
title: "Supplement: Streams"
date: 2020-10-04T16:30:22-05:00
draft: false
---

# C++ Streams
## Supplement

---

## The Streams You Know

### `std::cin` and `std::cout`

You are already familliar with the _standard input_ and _standard output_ streams (`cin` and `cout`, respectively).  But, you may not have considered much beyond the simplest basics about how they work.

This supplement will talk about how C++ supports a whole _family_ of streams and stream-like objects, and how they work on a conceptual level that may help you when you run into confusion with stream-processing tasks.

---

## The Stream You May Not

In addition to `cin` and `cout`, there is also a stream designed to communicate error messages out of your programs!  This one is named `std::cerr`, and it is the _standard error_ stream.  It behaves exactly like `cout` except that its output can be routed differently at the OS level:

``` {.cpp}
std::cerr << "This is an error message." << std::endl;
```

---

## File Streams

You have probably also seen streams attached to files, opened in "character mode" (also known as "text mode"):

``` {.cpp}
std::ifstream input_file_stream { "your_input_file.txt" };
std::ofstream output_file_stream { "your_output_file.txt" };
```

These streams behave exactly like their console I/O counterparts, except that the "other end" of the stream is attached to a file, whose name is specified when you open the stream.

---

## What does a stream look like?

When you imagine what a stream looks like (from the point-of-view of your program), what do you imagine?

Character-encoded streams are "seen" by the program as a series of characters (type `char`) and a _position_ in that series of characters that serves as a marker of the "current location".

Imagine a series of blocks with a character on each, stretching in a row off into the distance.  As you walk along this path of character blocks, _you_ are the "current location" marker.  Each time you walk past a block, it essentially fades into the "past" as far as you are concerned, and there are more character blocks ahead that you will walk by in "the future".

---


Let's visualize this as it exists in memory (more or less):

``` {.txt}
--------------------------------------------------------------------
|H|e|l|l|o| |W|o|r|l|d|!|\n|T|h|i|s| |i|s| |a| |s|t|r|e|a|m| |.|.|.|
--------------------------------------------------------------------
             ^
```

The caret (arrow) below the stream indicates the current position. The current position typically only moves "forward" (to the right in the figure).  It is possible to go back in some cases, though.

---

## Time is Relative

<img src='../images/shared/yellow_brick_road.jpg' style=' max-height: 500px; float: right;' />

Here's where it can get confusing.  From a stream's point-of-view, there is no end to this row of characters (as long as the stream is open).  

Although you might walk to a position where you don't see any more blocks in front of you _now_, more may appear at any moment.

If new characters appear, you can continue walking along the stream.



---

You have observed this effect every time you've prompted the user to enter some keyboard input.  Like this:

``` {.cpp}
int x;
cout << "Enter an integer: ";
cin  >> x;
cout << "Great!\n";
```

This code will appear to "stop and wait" on the line beginning with `cin` until the user types some characters and presses `<ENTER>`.  

From the program's standpoint, it is just waiting for the stream to increase in length so that it can "walk" along it further.  When the user pressed `<ENTER>`, more characters appeared and the walk continued.

---

File streams are different from user input -- all of the data that will exist in the file is (usually) _already there_ when the file is opened.

Imagine you want to read three integers:

``` {.cpp}
int a, b, c;
input_file_stream >> a >> b >> c;
```

---

``` {.cpp}
int a, b, c;
input_file_stream >> a >> b >> c;
```

This works fine, assuming the file looks like this:

``` {.txt}
5
12
17
```

Or, even this:

``` {.txt}
5 12 17
```

---

From the moment the stream is _opened_ (from your program's point-of-view), **all** of the input is already in the stream!

``` {.txt}
----------------------
|5| |1|2| |1|7|\n|EOF|
----------------------
 ^
```
The streams position is initially at the start.  As the stream extraction operator sees characters matching the signature of an `int`, it "walks" the stream to the right, until a whitespace.  

---

After `a` is extracted (the 5 is read), the stream will look like this:

``` {.txt}
----------------------
|5| |1|2| |1|7|\n|EOF|
----------------------
   ^
```

The stream's position is at the first space character.  (The stream extraction operator does not "remove" the delimiter, meaning it doesn't walk past it.)

---

Now let's consider a different case.  We want to read an ID number (integer) followed by a full name (which will contain spaces).  We might do this:

``` {.cpp}
int id;
std::string name;
input_file_stream >> id;
getline(input_file_stream, name);
cout << name << " is ID number " << id << '\n';
```

Let's assume an input file like this:

``` {.txt}
324
Alice Sanders
```

---


``` {.txt}
324
Alice Sanders
```

The input will **fail** to do what we _want_.  (You should expect it though, if you've used `getline()` before...)  Here's the code again:

``` {.cpp}
int id;
std::string name;
input_file_stream >> id;
getline(input_file_stream, name);
cout << name << " is ID number " << id << '\n';
```

The output would be:

``` {.txt}
 is ID number 324
```

Where did the name go?

---

## The name is in the future.

That's right -- the name is still in the stream's "future".  Let's look at the stream.  Here it is at the moment we open the file:

``` {.txt}
---------------------------------------
|3|2|4|\n|A|l|i|c|e| |S|a|n|d|e|r|s|\n|
---------------------------------------
 ^
```

We do `input\_file\_stream >> id;`.  Now the stream is:

``` {.txt}
---------------------------------------
|3|2|4|\n|A|l|i|c|e| |S|a|n|d|e|r|s|\n|
---------------------------------------
       ^
```

The stream extraction operator **_doesn't walk past the delimiter_**.

---

``` {.txt}
---------------------------------------
|3|2|4|\n|A|l|i|c|e| |S|a|n|d|e|r|s|\n|
---------------------------------------
       ^
```

Now we do `getline(input\_file\_stream, name);`.

The first thing in the stream is the `\n`, which is the delimiter for `getline()`, so it happily _removes_ the delimiter and stops.  It didn't read anything useful, so the name remains empty.  The stream is:

``` {.txt}
---------------------------------------
|3|2|4|\n|A|l|i|c|e| |S|a|n|d|e|r|s|\n|
---------------------------------------
          ^
```

---

This is why we have to use `ignore()` when mixing stream extraction operators and `getline()`.  We have to walk past anything that looks like a delimiter.

This code is correct:

``` {.cpp}
int id;
std::string name;
input_file_stream >> id;
input_file_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
getline(input_file_stream, name);
cout << name << " is ID number " << id << '\n';
```

`ignore()` will "keep walking" until it sees the `\n` or the end of the stream's current content.  

---

`ignore()` will "keep walking" until it sees the `\n` or the end of the stream's current content.  It will walk past the delimiter too, so after the `ignore` call, the stream would look like:

``` {.txt}
---------------------------------------
|3|2|4|\n|A|l|i|c|e| |S|a|n|d|e|r|s|\n|
---------------------------------------
          ^
```

That's perfect for the `getline()`.  

But **we only needed to do this because the** `>>` **left the delimiter in our path**.  Don't assume you always need to use `ignore()`.  You have to think about what the stream actually looks like.

---

## Streams can go bad...

Whenever we try to operate on a stream, but the stream is unable to complete the operation successfully, the stream can "go bad".  This actually isn't a single condition, but three:

* The "bad" bit is set.
  * Read/writing error on i/o operation.
* The "EOF" bit is set.
  * End-of-File was reached on input operation.
* The "fail" bit is set.
  * Logical error on i/o operation.

\(Ref: http://www.cplusplus.com/reference/ios/ios/good/ \)

---

## Check for bad streams...

It is easy to check for these "bad" stream conditions.  There are four stream methods you should keep in mind:

* `good()` : Returns `true` if none of the failure indicator bits are set, indicating the stream is "good" and ready for use.
* `eof()` : Returns `true` if the "eof" bit is set.  Cannot read from a stream in this condition.  Attempts to do so also set the "fail" bit.
* `bad()` : Returns `true` if the "bad" bit is set.  Most stream operations will fail while this condition is present.  May not be recoverable.
* `fail()` : Returns `true` if the "fail" or the "bad" bit is set.  May be able to resume operation after a `clear()`.

---

## We can clean up a bad stream.

If the stream has failed due to an operation like trying to read an integer when the next value in the stream was a string, or reading at the end of file, we can clear the state flags and restore the stream to a "good" state with the `clear()` method.

---

**Example**

File:

``` {.txt}
Hello 42
```

Code:

```{.cpp}
int x;
std::string msg;
input_file_stream >> x;         // will fail; a string is first in the file.
if(!input_file_stream.good()){
    cerr << "Stream error... trying again." << endl;
    input_file_stream.clear();  // clears the fail bit.
}
input_file_stream >> msg;       // works; a string is there.
input_file_stream >> x;         // works now, an int is the next token
cout << msg << " " << x << endl;
```

---

#### References 

<small>

`<iostream>` - C++ Reference:  http://www.cplusplus.com/reference/iostream/

`istream` - C++ Reference:  http://www.cplusplus.com/reference/istream/istream/

`ostream` - C++ Reference:  http://www.cplusplus.com/reference/ostream/ostream/

`istream::operator>>` - C++ Reference:  http://www.cplusplus.com/reference/istream/istream/operator%3E%3E/

`ostream::operator<<` - C++ Reference:  http://www.cplusplus.com/reference/ostream/ostream/operator%3C%3C/

C++ Files and Streams - Tutorialspoint:  https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm

A Gentle Introduction to IO Streams in C++ - Cprogramming.com:  https://www.cprogramming.com/tutorial/c++-iostreams.html

</small>

