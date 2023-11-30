#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stac;
        for (char ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stac.push(ch);
            }
            else
            {
                if (stac.empty() ||
                    (ch == ')' && stac.top() != '(') || (ch == '}' && stac.top() != '{') || (ch == ']' && stac.top() != '['))
                    {
                        return false;
                    }
                stac.pop();
            }
        }
        return stac.empty();
    }
};