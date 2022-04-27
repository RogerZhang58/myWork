// @algorithm @lc id=474 lang=cpp
// @title ones-and-zeroes

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(["10","0001","111001","1","0"],5,3)=4
// @test(["10","0","1"],1,1)=2
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int length = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < length; i++)
        {
            int zeros = 0, ones = 0, strlength = strs[i].size();
            for (int j = 0; j < strlength; j++)
            {
                strs[i][j] == '0' ? zeros++ : ones++;
            }
            for (int j = m; j >= zeros; j--)
            {
                for (int k = n; k >= ones; k--)
                {
                    dp[j][k] = dp[j][k] > dp[j - zeros][k - ones] + 1 ? dp[j][k] : dp[j - zeros][k - ones] + 1;
                }
            }
        }
        return dp[m][n];
    }
};