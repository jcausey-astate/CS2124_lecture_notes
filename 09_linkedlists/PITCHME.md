# Linked Lists

### (Ch 17) 

---

## The Linked List ADT
* **_Linked list_**: set of data structures (_nodes_) that contain references to other data structures
    - Relationship is linear:  Each node references the next node (and sometimes the previous node).
* References may be addresses (pointers) or array indices
* Data can be added/removed during execution.

![linked list](https://raw.githubusercontent.com/jcausey-astate/CS2124_lecture_notes/master/assets/images/LinkedList/LinkedList.svg?sanitize=true)

---

## Linked Lists

* Can grow or shrink as needed (unlike arrays).

![linked list](https://raw.githubusercontent.com/jcausey-astate/CS2124_lecture_notes/master/assets/images/LinkedList/LinkedList_add_end.svg?sanitize=true)

* Can insert data between other nodes easily.

![linked list](https://raw.githubusercontent.com/jcausey-astate/CS2124_lecture_notes/master/assets/images/LinkedList/LinkedList_add_mid.svg?sanitize=true)

---

## What is a “Node”?

* Contains some sort of data.
* Contains a reference (pointer or array index) to the “next” node in the list.

![linked list](https://raw.githubusercontent.com/jcausey-astate/CS2124_lecture_notes/master/assets/images/LinkedList/LinkedList_node.svg?sanitize=true)

---

## Lists are Made of Nodes

* Linked lists contain 0 or more nodes.
* Must have an “entry point” to the list.  We call it the list “head”.
* The end of the list usually points to NULL.
* A list containing 0 nodes is an _empty list_.

![linked list](https://raw.githubusercontent.com/jcausey-astate/CS2124_lecture_notes/master/assets/images/LinkedList/LinkedList_empty.svg?sanitize=true)

---

## Basic Operations

* Add node at the front (head) of the list.
* Add node at the end (tail) of the list.
* Add a node in-order in a sorted list.
* Traverse the linked list.
* Search the list.
* Delete a node (from head/tail/arbitrary).
* Empty the list.


