// @algorithm @lc id=215 lang=cpp
// @title kth-largest-element-in-an-array

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,2,1,5,6,4],2)=5
// @test([3,2,3,1,2,4,5,5,6],4)=4
class Solution
{
public:
    int quickSelect(vector<int> &a, int l, int r, int index)
    {
        int q = randomPartition(a, l, r);
        if (q == index)
        {
            return a[q];
        }
        else
        {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int> &a, int l, int r)
    {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int> &a, int l, int r)
    {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j)
        {
            if (a[j] <= x)
            {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};