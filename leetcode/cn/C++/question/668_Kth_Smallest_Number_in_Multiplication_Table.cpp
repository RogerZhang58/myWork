// @algorithm @lc id=668 lang=cpp
// @title kth-smallest-number-in-multiplication-table

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(3,3,5)=3
// @test(2,3,6)=6
class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int left = 1, right = m * n;
        while (left < right)
        {
            int x = left + (right - left) / 2;
            int count = x / n * n;
            for (int i = x / n + 1; i <= m; i++)
            {
                count += x / i;
            }
            if (count >= k)
            {
                right = x;
            }
            else
            {
                left = x + 1;
            }
        }
        return left;
    }
};