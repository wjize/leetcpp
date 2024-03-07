/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
        /*
        1.  template< class ForwardIt >
            ForwardIt unique( ForwardIt first, ForwardIt last );
            第一个版本接受两个迭代器参数 first 和 last，表示要去重的范围是 [first, last)，返回一个新的尾部迭代器，指向去重后的范围的尾部(最后一个的下一个元素)。
        2.  template< class ForwardIt, class BinaryPredicate >
            ForwardIt unique( ForwardIt first, ForwardIt last, BinaryPredicate p );
            第二个版本还接受一个二元谓词 p，用于自定义去重的判定条件。
        */

        /*
        1.  iterator erase(const_iterator pos);
            erase 函数接受一个迭代器参数 pos，表示要删除的元素的位置，返回一个迭代器，指向被删除元素的后一个元素（如果存在）或容器的 end()。
        2.  iterator erase(const_iterator first, const_iterator last);
            erase 函数接受两个迭代器参数 first 和 last，表示要删除的元素范围，返回一个迭代器，指向被删除元素的后一个元素（如果存在）或容器的 end()。
        3.  iterator erase(Iterator first, Iterator last, Predicate pred);
            erase 函数接受三个参数，first 和 last 表示要删除的元素范围，pred 是一个谓词函数，用于指定删除条件。这个版本通常与 std::remove_if 算法一起使用，结合起来可以删除容器中满足特定条件的元素。
        */
    }
};
// @lc code=end

