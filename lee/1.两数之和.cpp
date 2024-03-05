/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <map>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 创建map，key用于存放数组中出现的数字，value用于存放其下标
        map<int, int> num_map;
        // 两个index用于存放最终结果的两个下标
        int index = 0, index_2 = 0;
        for(vector<int>::iterator it = nums.begin(); it!= nums.end(); ++it,++index)
        {
            // target - *it 为target与数组中当前值差值
            if (num_map.find(target - *it) != num_map.end())  // 若map中找到了差值的下标
            {
                index_2 = num_map.find(target - *it) -> second;    //将下标取出放进index_2中
                break;    // 结束循环
            } else  // 若map中无差值下标
            {
                num_map[*it] = it - nums.begin();    //将当前数存入map中
            }
        }
        return vector<int> {index_2, index};
    }
};
// @lc code=end

