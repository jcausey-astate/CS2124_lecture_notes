---
title: "16a_QuickSort"
date: 2020-10-02T12:30:16-05:00
draft: false
---

## Quicksort

### (Ch. 20.8)

---

## Simple Sorting Methods

* Bubble Sort
* Selection Sort
* Insertion Sort <br /><br /><br />
* **All are $O(n^2)$** 
* A better algorithm is needed!

---

## Quicksort

Quicksort is a divide-and-conquer algorithm developed in 1960 by Tony Hoare.

<br />

It divides the array into two halves, and sorts those halves recursively.

---

## Quicksort

Quicksort divides the array into two halves, and sorts those halves recursively.

A _pivot_ element is chosen, then all elements greater than the pivot are moved to its right, and all elements less than the pivot are moved to its left.

The left and right sub-arrays are then sorted recursively.

---

## Algorithm

``` asciidoc
function quicksort(data[], n):
    if n > 1:
        choose pivot element;
        for each element in the array:
            if element < pivot:
                place in left_subarray;
            else:   // (element is >= pivot)
                place in right_subarray;
            end if;
        end for;
        quicksort(left_subarray, size_of_left_subarray);
        quicksort(right_subarray, size_of_right_subarray);
    end if;
end function quicksort;
```

---

<img src="../images/Quicksort/quicksort_anim.gif" width="80%">
<small style="font-size: 9pt;"><br />Image source: Wikipedia.org (https://en.wikipedia.org/wiki/File:Sorting_quicksort_anim.gif)</small>

---

## In-place Partitioning

<small style="font-size: 90%;">

``` asciidoc
// left is the index of the leftmost element of the array
// right is the index of the rightmost element of the array (inclusive)
// number of elements in subarray = right-left+1
function partition(data[], left, right, pivotIndex):
   pivotValue := array[pivotIndex];
   swap(array[pivotIndex], array[right]);  // Move pivot to end
   storeIndex := left;
   for i from left to right - 1 :          // left <= i < right
       if array[i] < pivotValue:
           swap(array[i], array[storeIndex]);
           storeIndex := storeIndex + 1;
   swap(array[storeIndex], array[right]);  // Move pivot to its final place
   return storeIndex;
end function partition;
```

</small>

---

## In-place Partitioning

> <img src="../images/Quicksort/partitioning.svg" alt="Partitioning" style="height: 20em;" title="In-place partitioning." />
>

---

## In-place Quicksort

**In-place quicksort:**

``` asciidoc
function quicksort(array[], left, right):
    // If the list has 2 or more items
    if left < right :
        // Choose a pivot (how you do this may vary):
        pivotIndex := choose any i such that left <= i <= right;
        // Get subarrays and final position of pivot
        splitLocation := partition(array, left, right, pivotIndex);
        // Recursively sort elements smaller than the pivot
        quicksort(array, left, splitLocation - 1);
        // Recursively sort elements at least as big as the pivot
        quicksort(array, splitLocation + 1, right);
    end if;
end function quicksort;
```

<br />

<br />

---

## In-place Quicksort

**In-place quicksort:**

``` asciidoc
function quicksort(array[], left, right):
    // If the list has 2 or more items
    if left < right :
        // Choose a pivot (how you do this may vary):
        pivotIndex := choose any i such that left <= i <= right;
        // Get subarrays and final position of pivot
        splitLocation := partition(array, left, right, pivotIndex);
        // Recursively sort elements smaller than the pivot
        quicksort(array, left, splitLocation - 1);
        // Recursively sort elements at least as big as the pivot
        quicksort(array, splitLocation + 1, right);
    end if;
end function quicksort;
```

<br />

** Complexity:  $O(n \cdot lg(n))$ (average)   $O(n^2)$ (worst)**

