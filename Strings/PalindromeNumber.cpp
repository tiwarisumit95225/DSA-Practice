// Problem: Palindrome Number
// Topic: Math
// Difficulty: Easy
// Pattern: Reverse Integer
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Key Learning: Extract digits using % 10 and remove digits using / 10.
// Reverse the number and compare it with the original number.

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        long long rev = 0;
        int num = x;

        while (num > 0)
        {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num = num / 10;
        }

        return rev == x;
    }
};