// @algorithm @lc id=713 lang=cpp
// @title subarray-product-less-than-k

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([10,5,2,6],100)=8
// @test([1,2,3],0)=0
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size(), ans = 0;
        int i = 0, prod = 1;
        for (int j = 0; j < n; j++)
        {
            prod *= nums[j];
            while (i <= j && prod >= k)
            {
                prod /= nums[i];
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};