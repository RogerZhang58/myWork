// @algorithm @lc id=100178 lang=cpp
// @title successor-lcci

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        int target = p->val;
        TreeNode *ans = nullptr;
        while (root != nullptr)
        {
            if (root->val <= target)
            {
                root = root->right;
            }
            else
            {
                ans = root;
                root = root->left;
            }
        }
        return ans;
    }
};