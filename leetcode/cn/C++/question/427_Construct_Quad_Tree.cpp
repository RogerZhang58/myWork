// @algorithm @lc id=772 lang=cpp
// @title construct-quad-tree

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([[0,1],[1,0]])=[[0,1],[1,0],[1,1],[1,1],[1,0]]
// @test([[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]])=[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]

// Definition for a QuadTree node.
// class Node
// {
// public:
//     bool val;
//     bool isLeaf;
//     Node *topLeft;
//     Node *topRight;
//     Node *bottomLeft;
//     Node *bottomRight;

//     Node()
//     {
//         val = false;
//         isLeaf = false;
//         topLeft = NULL;
//         topRight = NULL;
//         bottomLeft = NULL;
//         bottomRight = NULL;
//     }

//     Node(bool _val, bool _isLeaf)
//     {
//         val = _val;
//         isLeaf = _isLeaf;
//         topLeft = NULL;
//         topRight = NULL;
//         bottomLeft = NULL;
//         bottomRight = NULL;
//     }

//     Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
//     {
//         val = _val;
//         isLeaf = _isLeaf;
//         topLeft = _topLeft;
//         topRight = _topRight;
//         bottomLeft = _bottomLeft;
//         bottomRight = _bottomRight;
//     }
// };
class Solution
{
private:
    vector<vector<int>> sums;
    int getSum(int row1, int col1, int row2, int col2)
    {
        return sums[row2][col2] - sums[row2][col1] - sums[row1][col2] + sums[row1][col1];
    }
    Node *dfs(int row1, int col1, int row2, int col2)
    {
        int sum = getSum(row1, col1, row2, col2);
        if (sum == 0)
        {
            return new Node(false, true);
        }
        else if (sum == (row2 - row1) * (col2 - col1))
        {
            return new Node(true, true);
        }
        else
        {
            return new Node(true, false,
                            dfs(row1, col1, (row1 + row2) / 2, (col1 + col2) / 2),
                            dfs(row1, (col1 + col2) / 2, (row1 + row2) / 2, col2),
                            dfs((row1 + row2) / 2, col1, row2, (col1 + col2) / 2),
                            dfs((row1 + row2) / 2, (col1 + col2) / 2, row2, col2));
        }
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m > 0)
        {
            sums = vector(m + 1, vector(m + 1, 0));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + grid[i][j];
                }
            }
        }
        return dfs(0, 0, m, m);
    }
};