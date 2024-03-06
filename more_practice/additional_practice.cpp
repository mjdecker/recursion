/**
 *  @file sum.cpp
 *
 *  Some refactoring practice exercises.
 *
 *  @author Michael J. Decker, Ph.D. <mdecker@bgsu.edu>
 */

#include <iostream>
#include <vector>
#include <cassert>

/**
 * power
 * @param base     - base number
 * @param exponent - exponent number
 * 
 * Computes base^exponent. Exponent is non-negative
 * You must use recursion.  You may NOT use a loop.
 * 
 * @returns base^exponent
 * 
 */
int power(int base, int exponent) {
    if(exponent == 0) return 1;
    return base * power(base, exponent - 1);
}

/**
 * tri_fibonacci
 * @param num - nth tri fibonacci number
 * 
 * Computes the tri fibonacci number.  A tri fibonacci number is
 * F0 = 0
 * F1 = 1
 * F2 = 1
 * Fn = Fn-1 + Fn-2 + Fn-3
 * You must use recursion.  You may NOT use a loop.
 * 
 * @returns base^exponent
 * 
 */
int tri_fibonacci(int num) {
    if(num == 0) return  0;
    if(num == 1) return  1;
    if(num == 2) return  1;

    return tri_fibonacci(num - 1) + tri_fibonacci(num - 2) + tri_fibonacci(num - 3);
}




void reverse(std::vector<int>& vector, int first_pos, int last_pos);

/**
 * reverse
 * @param vector - vector with elements to reverse
 * 
 * Function user will call.  reverse_impl implements
 * actual reverse algorithm. We use this user facing
 * one to make call simpler 
 */
void reverse(std::vector<int>& vector) {
    reverse(vector, 0, vector.size() - 1);
}

/**
 * reverse_impl
 * @param vector - vector with elements to reverse
 * @param first_pos  - first element to swap in vector
 * @param last_pos   - second element to swap in vector
 * 
 * You must use recursion.  You may NOT use a loop.
 */
void reverse(std::vector<int>& vector, int first_pos, int last_pos) {
    if(last_pos <= first_pos) return;

    int temp = vector[first_pos];
    vector[first_pos] = vector[last_pos];
    vector[last_pos] = temp;

    reverse(vector, first_pos + 1, last_pos - 1);
}

int main(int argc, char * argv[]) {

    assert(power(5, 0) == 1);
    assert(power(7, 1) == 7);
    assert(power(2, 10) == 1024);

    assert(tri_fibonacci(0) == 0);
    assert(tri_fibonacci(1) == 1);
    assert(tri_fibonacci(2) == 1);
    assert(tri_fibonacci(0) == 0);
    assert(tri_fibonacci(1) == 1);
    assert(tri_fibonacci(5) == 7);
    assert(tri_fibonacci(10) == 149);

    {
        std::vector<int> vec = {};
        reverse(vec);
        assert(vec.empty());
    }

    {
        std::vector<int> vec = { 1 };
        reverse(vec);
        assert(vec == std::vector<int>({ 1 }));
    }

    {
        std::vector<int> vec = { 1, 2, 3, 4, 5 };
        reverse(vec);
        assert(vec == std::vector<int>({ 5, 4, 3, 2, 1 }));
    }

    {
        std::vector<int> vec = { 1, 2, 3, 4 };
        reverse(vec);
        assert(vec == std::vector<int>({ 4, 3, 2, 1 }));
    }

    return 0;
}
