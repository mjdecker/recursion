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

/**
 * 
 */
bool is_palindrome(const std::string & str) {
    if(str.size() < 2) return true;
    if(str.front() != str.back()) return false;
    return is_palindrome(str.substr(1, str.size() -2 ));
}

int main(int argc, char * argv[]) {

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
