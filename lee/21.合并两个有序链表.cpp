/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <iostream>

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode l = ListNode();
        ListNode* list = &l;
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        while (list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                list->next = list1;
                list1 = list1->next;
            }
            else
            {
                list->next = list2;
                list2 = list2->next;
            }
            list = list->next;
        }
        
        list->next = list1 ? list1 : list2;
        return l.next;
    }
};
// @lc code=end

