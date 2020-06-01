/**
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        int square;
        for(int i = 0; i < 46341 && (square = i * i) < num; i++);
        return square == num;
    }
};
