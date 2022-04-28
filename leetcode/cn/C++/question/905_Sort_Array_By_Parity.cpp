// @algorithm @lc id=941 lang=cpp
// @title sort-array-by-parity

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,1,2,4])=[2,4,3,1]
// @test([0])=[0]
// @test([3,1,2,4])=[2,4,3,1]
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int head = 0, end = nums.size() - 1;
        while (head < end)
        {
            while (head < end && nums[head] % 2 == 0)
                head++;
            while (head < end && nums[end] % 2 == 1)
                end--;
            int tmp = nums[end];
            nums[end] = nums[head];
            nums[head] = tmp;
        }
        return nums;
    }
};