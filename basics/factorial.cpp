/**
 *  @file factorial.cpp
 *
 *  Show recursion
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>


/**
 * Recursion - see Recursion
 * 
 * There are three essenstial parts to qualify as recursion
 * * At least 1 base case
 * * A recursive case, either directly (function calls itself)
 *   or indirectly (a sequence of calls eventially calls this function)
 * * The recursive case must make progress towards the base case. That is,
 *   recursion must end, and not be infinite.
 * 
 */

/**
 * factorial
 * @param num factorial to compute (i.e., num!)
 *
 * Compute factorial of num (i.e., num!) using regular recursion.
 *
 * @returns num!
 */
unsigned long long factorial(int num) {
    // base case
    if(num <= 1) return 1;

    // recursive case
    return num * factorial(num - 1);

}

unsigned long long bad_factorial_1(int num) {
    // missing base case

    // recursive case
    return num * bad_factorial_1(num);

}

unsigned long long bad_factorial_2(int num) {
    // base case
    if(num <= 1) return 1;

    // infinitely recursive
    return num * bad_factorial_2(num);

}


int main(int argc, char * argv[]) {

    std::cerr << "factorial(0):        " << factorial(0)  << '\n';
    std::cerr << "factorial(1):        " << factorial(1)  << '\n';
    std::cerr << "factorial(5):        " << factorial(5)  << '\n';
    std::cerr << "factorial(20):       " << factorial(20) << '\n';


    // Uncomment these (one at a time) to see what happens with missing
    // base case and infinite recursion
    //std::cerr << "bad_factorial_1(20): " << bad_factorial_1(20) << '\n';
    //std::cerr << "bad_factorial_2(20): " << bad_factorial_2(20) << '\n';

    return 0;
}
