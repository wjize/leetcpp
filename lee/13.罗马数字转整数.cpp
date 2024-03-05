/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp.insert(make_pair<char,int>('I',1));
        mp.insert(make_pair<char,int>('V',5));
        mp.insert(make_pair<char,int>('X',10));
        mp.insert(make_pair<char,int>('L',50));
        mp.insert(make_pair<char,int>('C',100));
        mp.insert(make_pair<char,int>('D',500));
        mp.insert(make_pair<char,int>('M',1000));

        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= s[i+1]) //这一步有问题。明天改
            {
                sum += mp.at(s[i]);
            }
            else
            {
                sum -+ mp.at(s[i]);
            }
        }

        return sum;   
    }
};
// @lc code=end

