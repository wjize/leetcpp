/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        // 找到最后一个非空格字符
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        // 计算最后一个单词的结束位置
        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        // 计算最后一个单词的长度
        return end - start;
    }
};
// @lc code=end

