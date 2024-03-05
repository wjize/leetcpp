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
        
        char buffer[20];
        sprintf(buffer,"%d",x);

        char* charpoint = buffer;
        int length = strlen(charpoint);
        for (int i = 0; i < length / 2; i++)
        {
            if (charpoint[i] != charpoint[length - i - 1])
            {
                return false;
            }
            
        }
        return true;
    }
};
// @lc code=end

