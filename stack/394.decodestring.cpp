// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 10^5.

// Intuition:
// Create two stacks, for strings and numbers.

// push string until a closing bracket is seen, when a closing bracket appears pop out the character until the opening bracket is seen.

// Since it is sure that we will see a number just before the opening bracket, go to the number stack and pop out the top of the number stack and repeat the recently popped string that number times.

// push the decoded string yet to the string stack back and repeat the same process.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numStack;
        stack<string> stringStack;
        string currentString = "";
        int currentNum = 0;

        for (char c : s)
        {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                currentString += c;
            }
            else if (isdigit(c))
            {
                currentNum = currentNum * 10 + (c - '0');
            }
            else if (c == '[')
            {
                numStack.push(currentNum);
                stringStack.push(currentString);
                currentNum = 0;
                currentString = "";
            }
            else if (c == ']')
            {
                int repeatCount = numStack.top();
                numStack.pop();
                string prevString = stringStack.top();
                stringStack.pop();
                currentString = prevString + repeatString(currentString, repeatCount);
            }
        }

        return currentString;
    }

private:
    string repeatString(string s, int times)
    {
        string result = "";
        for (int i = 0; i < times; ++i)
        {
            result += s;
        }
        return result;
    }
};
