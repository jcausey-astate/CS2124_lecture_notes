---
title: "09a_LinkedLists"
date: 2020-10-02T12:30:15-05:00
draft: false
---

## Linked Lists

### (Ch. 18) 

---

## The Linked List ADT
* **_Linked list_**: set of data structures (_nodes_) that contain references to other data structures
    - Relationship is linear:  Each node references the next node (and sometimes the previous node).
* References may be addresses (pointers) or array indices
* Data can be added/removed during execution.

.center[![:scale Linked List, 80%](../images/LinkedList/LinkedList.svg)]

---

## Linked Lists

* Can grow or shrink as needed (unlike arrays).

.center[![:scale Adding at the end of a linked list., 80%](../images/LinkedList/LinkedList_add_end.svg)]

* Can insert data between other nodes easily.

.center[![:scale Adding in the middle of a linked list., 50%](../images/LinkedList/LinkedList_add_mid.svg)]

---

## What is a “Node”?

* Contains some sort of data.
* Contains a reference (pointer or array index) to the “next” node in the list.

.center[![:scale Linked list node., 50%](../images/LinkedList/LinkedList_node.svg)]

---

## Lists are Made of Nodes

* Linked lists contain 0 or more nodes.
* Must have an “entry point” to the list.  We call it the list “head”.
* The end of the list usually points to `nullptr`.
* A list containing 0 nodes is an _empty list_.

.center[![:scale Empty linked list., 20%](../images/LinkedList/LinkedList_empty.svg)]

---

## Basic Operations

* Add node at the front (head) of the list.
* Add node at the end (tail) of the list.
* Add a node in-order in a sorted list.
* Traverse the linked list.
* Search the list.
* Delete a node (from head/tail/arbitrary).
* Empty the list.


