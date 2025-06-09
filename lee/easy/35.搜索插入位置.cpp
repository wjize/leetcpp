/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            if (nums.at(mid) == target)
                return mid;
            else if (nums.at(mid) < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        return begin;
    }
};
// @lc code=end

