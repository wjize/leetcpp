/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false;
        vector<char> left = {'(','[','{'};
        vector<string> str = {"()","[]","{}"};
        stack<char> mystack;

        for (int i = 0; i < s.size(); i++)
        {
            if (find(left.begin(),left.end(),s[i]) != left.end())
                mystack.push(s[i]);
            else
            {
                if (mystack.empty())
                    return false;
                string mach_str = string(1,mystack.top()) + s[i];
                mystack.pop();
                if (find(str.begin(), str.end(), mach_str) != str.end())
                    continue;
                else
                    return false;
            }
        }
        if (mystack.empty())
            return true;

        return false;
    }
};
// @lc code=end

