/**
 * This program illustrates the basic concept 
 * of exception handling in C++.
 */
#include <iostream>
#include <string>
#include <stdexcept>  // see http://www.cplusplus.com/reference/stdexcept/

std::string to_medal_color(int place);

int main() {
    int rank = 1;
    // This part works, 1 is a valid ranking...
    std::string color = to_medal_color(rank);
    std::cout << "The color for ranking #"
              << rank << " is " 
              << color << ".\n";

    // Now let's try it with an invalid ranking
    rank = 12;
    try{
        color = to_medal_color(rank);
        std::cout << "The color for ranking #"
                  << rank << " is " 
                  << color << ".\n";
    }
    catch( std::invalid_argument ){
        // Note: `cerr` is the "standard error" output stream.
        //       You use it like `cout` for error messages.
        std::cerr << rank << " is not a valid rank for a medal.\n";
        std::cerr << "Rank must be either 1, 2, or 3.\n";
    }

    std::cout << "Exiting.\n";
    return 0;
}

/**
 * converts a numerical ranking in {1,2,3} to the corresponding 
 * medal color from {"gold","silver","bronze"}
 * 
 * @param  rank  integer numerical ranking; should be in {1,2,3}
 * @return the corresponding metal color for `rank` is returned 
 *         from the set {"gold", "silver", "bronze"}.
 * @throw  std::invalid_argument is thrown if `rank` is not one
 *         of {1,2,3}.
 */
std::string to_medal_color(int rank){
    std::string color;
    if(rank == 1)      color = "gold";
    else if(rank == 2) color = "silver";
    else if(rank == 3) color = "bronze";
    else 
        throw std::invalid_argument{
            "Invalid rank; rank must be in {1,2,3}."
        };
    return color;
}
