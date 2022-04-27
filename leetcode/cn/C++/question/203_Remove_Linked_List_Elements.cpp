// @algorithm @lc id=203 lang=cpp
// @title remove-linked-list-elements

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,6,3,4,5,6],6)=[1,2,3,4,5]
// @test([],1)=[]
// @test([7,7,7,7],7)=[]
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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *ans = new ListNode(0, head);
        ListNode *tmp = ans;
        while (tmp->next != nullptr)
        {
            if (tmp->next->val == val)
                tmp->next = tmp->next->next;
            else
                tmp = tmp->next;
        }
        return ans->next;
    }
};