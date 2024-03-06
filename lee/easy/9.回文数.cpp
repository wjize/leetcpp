/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <iostream>
#include <string>
#include <cstdio>

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        std::string xstr = std::to_string(x);
        for (int i = 0; i < xstr.length() / 2; i++)
        {
            if (xstr[i] != xstr[xstr.length() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

