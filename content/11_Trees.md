---
title: "11_Trees"
date: 2020-10-02T12:30:16-05:00
draft: false
marp: true
---

## Trees
### Featuring: The Binary Search Tree
#### (Ch. 20)

---

## Trees
In the computer science sense, trees are simply non-linear linked structures where each node may link to two or more other nodes, in a _hierarchical_ fashion.

* The entry point into a tree is called the _**root**_.
* Trees are (usually) drawn "upside down", with the root at the top.
* Normally, we don’t draw the null pointers when we draw a tree... but we must remember that they are there.


---
background-image: url(../images/Trees/trees.png)

&nbsp;

---

## Trees
We use terms borrowed from family trees to describe the hierarchical relationships between nodes in CS trees.<br />  (parent, child, grandparent, sibling, etc.)

* Interior nodes – have at least one child
* Leaf nodes – have no children
* Edge - A non-null outgoing link from a node to its child node.
* Height - Longest path along edges from root to any leaf, plus one.
    - (The empty tree is height 0, a single node is height 1)
* Subtree - any node in the tree, and all its descendents.

---
background-image: url(../images/Trees/trees.png)

&nbsp;

---

## Binary Trees

A _binary tree_ is a tree in which each node has up to two children.

* These are the most common type
* Easy to design and conceptualize (and code)
* Useful in many contexts
* The order of the values may or may not matter.

---
## Binary Tree Node

The binary tree "Node" must store a payload value and maintain pointers to the left and right subtree.

.center[![](../images/Trees/Binary_Tree_Node.svg)]

---

## Binary Tree

The "Tree" object must store an owning pointer to the root of the tree.  The tree itself has ownership responsibility too all nodes in the data structure.

.center[![](../images/Trees/Binary_Tree.svg)]


---

## Binary Search Trees

A _Binary Search Tree_ is a binary tree that has the following additional properties: 

* From any node in the tree, the left child (if non-null) has a smaller value than the parent.
* From any node in the tree, the right child (if non-null) has a larger value than the parent.

As the name implies, Binary Search Trees are optimized for searching.

---

## Binary Search Trees

* Order of data addition affects efficiency.
    - “Random” arrival
    - Non-random (partially ordered) arrival
    - Discuss best, average, worst cases.

---

## Code examples

* Add items
* Search for items
* Traversals
    - In-order
    - pre-order
    - post-order
* What would be involved with removing items?
