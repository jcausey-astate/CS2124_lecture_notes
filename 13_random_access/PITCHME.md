## Random Access Files
### (Ch. 12)

---

## Files – Review

_**File**_: a set of data stored on a computer; often on secondary storage such as a disk drive.

* Used to abstract the concept of "a blob of data" in a well-understood and system-wide way.
* Can be read and/or written (depending on permissions).

---

## Files – Review

* Requires the `fstream` header file.
* `ifstream` objects are specialized for input
* `ofstream` object are specialized for output
* `fstream` objects are more general – can do both input and output.
* Operators `<<` and `>>` work with file streams.
* `get()` and `getline()` also work with file streams.

---

## `fstream`  Object

* Can be used for input and/or output.
* Must specify the _mode_ when opening the file.
    - `ios::in`  – input
    - `ios::out` – output
    - `ios::app` – append
    - There are others...
* Modes may be combined with bitwise OR:
    -  `ios::in | ios::out`  - gives input and output.

---

**File modes**

<small>

| `ios::openmode`   | Meaning |
|-------------------|-------------------------------------------|
| `ios::app `       | Append mode.  If the file exists, all output is written to the end of the file. Create the file if it does not exist.   |
| `ios::ate`        | If the file exists, the initial position markers are moved to the end of it.  |
| `ios::binary `    | Binary mode.  Data is written/read in pure binary format (no en/decoding takes place)|
| `ios::in `        | Input mode.  Data will be read from the file.  If the file does not exist, it will not be created and the open will fail. |
| `ios::out`        | Output mode.  Data will be written to the file. By default, the file's contents will be deleted if it already exists; it will be created otherwise.|
| `ios::trunc `     | If the file already exists, its contents will be deleted (truncated).  This is the default mode used by `ios::out`.|

</small>


---

## Binary Files

* The default open mode is "text mode"
    - ASCII – encoded text
* Opening in "binary mode" (ios::binary) means no encoding scheme is used.
    - So, raw binary data is written as-is.
    - Use `read()` and `write()` methods instead of `>>` and `<<`.

**Example**
``` cpp
char ch;
fin.read(&ch, sizeof(ch)); // read 1 character.
```

---

## Binary Files

To read/write non-character data, you must cast using:
``` cpp
reinterpret_cast<char*>( address_of_object )
```

_**Reason:**_  The `read()` and `write()` methods are designed to input/output raw _bytes_ of data.  `char` is a convenient "package" for raw bytes. `reinterpret_cast` forces the compiler to treat a pointer/address of one type as if it were another.

---

## Random Access

The idea is to create an "array-in-a-file" that can be accessed at any arbitrary location (index or offset) easily.

* Should probably be called "arbitrary access files".
* Each item in the file (called a record) must be the same size.
* Structures and classes are both perfect for this.
    - (provided they are constant-sized)

---

## Random Access

* Open the file for both input and output.
    -  While not always necessary, it often is.
* Open file in binary mode
    - ASCII-encoding would be undesirable
* Move to desired location (_seek_)
    - You can seek the read and write position independently.
* Read or write a record (or records).
    - Must be done as a series of bytes (`char`s).

---

## Positioning

**`seekg()`** : "seek get" – move the "read pointer"

**`seekp()`** : "seek put" – move the "write pointer".

* Can be used to go to any location in a file.
* Math similar to pointer-based array access is used.

**Syntax:**    
_`stream`_`.seekg(`_`offset`_`, `_`mode`_`)`       
_`stream`_`.seekp(`_`offset`_`, `_`mode`_`)`

Where _stream_ is the file stream, offset_ is distance to seek (bytes), _mode_ is where to start from (mathematically).

``` cpp
// seek 25 bytes from the beginning of stream `fin`
fin.seekg(25L, ios::beg); 
```

---

## Useful `ios` Methods

**_`stream`_`.seekg()`** : seek "get" to an offset in _`stream`_

**_`stream`_`.seekp()`** : seek "put" to an offset in _`stream`_

**_`stream`_`.read()`** : read raw bytes from _`stream`_

**_`stream`_`.write()`** : write raw bytes to _`stream`_

**_`stream`_`.clear()`** : clear _`stream`_'s _state flags_

**_`stream`_`.tellg()`** : where is the "get" pointer?

**_`stream`_`.tellp()`** : where is the "put" pointer?

---

## Zero Memory Quickly

For security, it is often desirable to clear _all_ bytes associated with an object's memory allocation.  This can be done efficiently with `memset()`:

**`memset()`** : (not a method) – useful for clearing memory within a record.

* `memset` is defined in the `<cstring>` header file.

**Syntax:**      
`memset(`_`start`_`, `_`value`_`, `_`size`_`)`

``` cpp
// zero all bytes contained in `myObj`:
memset(&myObj, 0, sizeof(myObj));
```