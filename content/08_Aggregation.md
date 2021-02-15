---
title: "08_Aggregation"
date: 2020-10-02T12:30:15-05:00
draft: false
marp: true
---

# Aggregation <br />of<br />Objects

---

## Aggregation

* _Aggregation_: an object of one class is used as an attribute in another class
* Sometimes called _composition_
* Creates the _"has a" relationship_.

Large book example in Chapter 14

    Instructor
    Textbook
    Course

---

__*Example*__

```cpp
class Tool{
    private:
        std::string name;
        double      weight;
    public:
        [...] // interface not shown for brevity
};

class ToolBox{
    private:
        Tool inventory[1024]; // aggregation of "Tool" objects
    public:
        [...] // interface not shown for brevity
};
```
