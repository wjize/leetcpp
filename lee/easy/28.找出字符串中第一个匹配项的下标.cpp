/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
}

};
// @lc code=end

