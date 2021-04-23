---
title: "09b_Doubly_Linked_Lists"
date: 2020-10-02T12:30:16-05:00
draft: false
---

## Doubly-Linked Lists
### (Ch. 18)

---

## Doubly-Linked List

A _doubly-linked list_ is a linked list in which the _nodes_ support access to both the _next_ and _previous_ items in the list, allowing bidirectional traversal.


![doubly-linked list](../images/LinkedList/Doubly-Linked_List.svg)

---

## A Doubly-Linked Node

```cpp
class DL_IntNode{
    private:
        int data;
        DL_IntNode* prev = nullptr;   // NEW
        DL_IntNode* next = nullptr;
    public:
        // [...] Public interface same as singly-linked list.
};
```

A doubly-linked list's _node_ is different only in that it maintains one extra link &mdash; in this case, a pointer `prev` to the previous node.

![doubly-linked list](../images/LinkedList/Doubly-Linked_List.svg)


---

## Considerations for List Operations

Because the list is linked in two directions, list operations are affected in that they must maintain the correct links:

* add to list
    - at front
    - at back
* remove from list
    - at front
    - at back
* clear / destroy the list

Additionally, new _traversals_ are possible (traversing the list in reverse, for example).

---

## Advantages and Drawbacks

* Advantages
    - Reverse traversal is possible
    - Remove at tail becomes $O(1)$
* Drawbacks
    - Added complexity of list maintenance code
    - Storage requirements
        + _compare cost of adding a pointer `prev` in the **node** <br /> versus adding a pointer `tail` in the **list**_