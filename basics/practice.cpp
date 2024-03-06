/**
 *  @file sum.cpp
 *
 *  This is a generic C++ main file.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include <cassert>

/**
 * sum
 * @param num - sum the numbers up to and including num
 * 
 * You must use recursion.  You may NOT use a loop or the Gauss equation: (num * (num  + 1)) / 2.
 * Hint: Sum of N is same as N + sum of (N - 1).
 * 
 * @returns sum of numbers [1, num]
 */
int sum(int num) {
    if(num < 1) return -1;
    if(num == 1) return 1;
    return num + sum(num - 1);

}

/**
 * is_palindrome
 * @param str - string to check if palindrome
 * 
 * You must use recursion.  You may NOT use a loop.
 * 
 * Hint: you may use substr, a string of at most 1 characters is a palindrome,
 *       and you can have multiple base cases.
 * 
 * @returns if str is a palindrome
 */
bool is_palindrome(const std::string & str) {
    if(str.size() < 2) return true;
    if(str.front() != str.back()) return false;
    return is_palindrome(str.substr(1, str.size() -2 ));
}

int main(int argc, char * argv[]) {

    assert(sum(1) == 1);
    assert(sum(10) == 55);
    assert(sum(100) == 5050);
    assert(sum(9001) == 40513501);

    assert(is_palindrome(""));
    assert(is_palindrome("a"));
    assert(is_palindrome("aa"));
    assert(!is_palindrome("ab"));
    assert(is_palindrome("racecar"));
    assert(!is_palindrome("trapcart"));
    assert(is_palindrome("rats live on no evil star"));

    return 0;
}
