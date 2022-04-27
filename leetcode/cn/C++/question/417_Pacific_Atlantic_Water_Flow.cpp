// @algorithm @lc id=417 lang=cpp
// @title pacific-atlantic-water-flow

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]])=[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// @test([[2,1],[1,2]])=[[0,0],[0,1],[1,0],[1,1]]
static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution
{
public:
    void dfs(int row, int col, vector<vector<bool>> &ocean, vector<vector<int>> &heights)
    {
        if (ocean[row][col])
            return;
        int m = ocean.size();
        int n = ocean[0].size();
        ocean[row][col] = true;
        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + dirs[i][0], nextCol = col + dirs[i][1];
            if (nextCol < n && nextCol >= 0 && nextRow < m && nextRow >= 0 && heights[nextRow][nextCol] >= heights[row][col])
            {
                dfs(nextRow, nextCol, ocean, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, pacific, heights);
            dfs(i, n - 1, atlantic, heights);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(0, i, pacific, heights);
            dfs(m - 1, i, atlantic, heights);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    vector<int> cell;
                    cell.emplace_back(i);
                    cell.emplace_back(j);
                    result.emplace_back(cell);
                }
            }
        }
        return result;
    }
};