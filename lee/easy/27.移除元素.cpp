/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it = nums.begin();
        while (it != nums.end())
        {
            it = find(nums.begin(), nums.end(), val);
            if (it != nums.end())
                nums.erase(it);
        }
        return nums.size();
    }
};
// @lc code=end

