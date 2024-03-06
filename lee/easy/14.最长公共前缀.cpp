/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
/*
eg1:
输入：strs = ["flower","flow","flight"]
输出："fl"

eg2:
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        if (strs.empty()) {
            return s;
        }

        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return s;
                }
            }
            s += c;
        }
        return s;

        /*
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
            int i = 0;
            for (vector<string>::iterator it2 = it + 1; it2 != strs.end(); ++it2) {
                if (i >= it->size() || i >= it2->size() || (*it)[i] != (*it2)[i]) {
                    return s;
                }
        }
        s += (*it)[i];
        return s; 
        */
    }
};
// @lc code=end

