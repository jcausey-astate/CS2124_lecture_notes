---
title: "Easy_rand"
date: 2020-10-02T12:30:16-05:00
draft: false
---


<small style="font-size: 100%; margin-left: -3em; min-width: 95%; height: 100%; margin-top: -100px;">
```cpp
#include <random>
/**
 * @brief   returns a pseudo-random integer in the interval [low, high]
 * @details Sets up an mt19937 Mersenne Twister random number generator
 *          using a random seed obtained from the best entropy source
 *          available to the <random> library.
 *          Notice:  first call incurs additional setup time.
 * 
 * @param low  lower-bound of interval for random value (included in interval)
 * @param high upper-bound of interval for random value (included in interval)  
 * 
 * @return pseudo-random integer in the range [low, high]
 */
int rand_between(int low, int high){
    // used to seed with system entropy
    static std::random_device            seeder;                    
    // set up (and seed) the PRNG
    static std::mt19937                  generator{seeder()};       
    // set up distribution for requested range
    std::uniform_int_distribution<int>   distribution{low, high};   
    // generate and return result
    return distribution(generator);                                 
}

```
</small>