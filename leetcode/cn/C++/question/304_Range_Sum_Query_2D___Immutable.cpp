// @algorithm @lc id=304 lang=cpp
// @title range-sum-query-2d-immutable
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class NumMatrix
{
private:
    vector<vector<int>> sums;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        if (m > 0)
        {
            sums = vector(m + 1, vector(n + 1, 0));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
    }
};