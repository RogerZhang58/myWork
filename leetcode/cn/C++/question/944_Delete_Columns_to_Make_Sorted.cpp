// @algorithm @lc id=981 lang=cpp
// @title delete-columns-to-make-sorted

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(["cba","daf","ghi"])=1
// @test(["a","b"])=0
// @test(["zyx","wvu","tsr"])=3
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                if (strs[i][j] < strs[i - 1][j])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};