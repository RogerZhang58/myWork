// @algorithm @lc id=449 lang=cpp
// @title serialize-and-deserialize-bst

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([2,1,3])=[2,1,3]
// @test([])=[]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans;
        vector<int> arr;
        encode(root, arr);
        if (arr.size() == 0)
            return ans;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            ans.append(to_string(arr[i]) + ',');
        }
        ans.append(to_string(arr.back()));
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string &data)
    {
        if (data.size() == 0)
            return nullptr;
        vector<int> arr = split(data);
        return decode(arr, INT_MIN, INT_MAX);
    }

    TreeNode *decode(vector<int> &arr, int low, int high)
    {
        if (arr.size() == 0 || arr[0] < low || arr[0] > high)
            return nullptr;
        int val = arr[0];
        arr.erase(arr.begin());
        TreeNode *root = new TreeNode(val);
        root->left = decode(arr, low, val);
        root->right = decode(arr, val, high);
        return root;
    }

    vector<int> split(string &data)
    {
        int pos = 0, start = 0, n = data.size();
        vector<int> ans;
        while (pos < n)
        {
            while (pos < n && data[pos] == ',')
                pos++;
            start = pos;
            while (pos < n && data[pos] != ',')
                pos++;
            if (start < n)
                ans.emplace_back(stoi(data.substr(start, pos - start)));
        }
        return ans;
    }

    void encode(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }
        arr.emplace_back(root->val);
        encode(root->left, arr);
        encode(root->right, arr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;