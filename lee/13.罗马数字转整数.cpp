/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        /*
            map有序，底层红黑树
            unordered_map无序，底层哈希表
        */
        //unordered_map<char,int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        unordered_map<char,int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] >= mp[s[i+1]]) 
                sum += mp[s[i]];
            else
                sum -= mp[s[i]];
        }
        //MCMXCIV
        return sum; 
    }
};
// @lc code=end

