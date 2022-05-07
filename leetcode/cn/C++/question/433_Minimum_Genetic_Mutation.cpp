// @algorithm @lc id=433 lang=cpp
// @title minimum-genetic-mutation

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algm/algm.h"
using namespace std;
// @test("AACCGGTT","AACCGGTA",["AACCGGTA"])=1
// @test("AACCGGTT","AAACGGTA",["AACCGGTA","AACCGCTA","AAACGGTA"])=2
// @test("AAAAACCC","AACCCCCC",["AAAACCCC","AAACCCCC","AACCCCCC"])=3
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        int m = start.size();
        int n = bank.size();

        int endIndex = -1;

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {
            if (end == bank[i])
            {
                endIndex = i;
            }
            for (int j = i + 1; j < n; j++)
            {
                int mutation = 0;
                for (int k = 0; k < m; k++)
                {
                    if (bank[i][k] != bank[j][k])
                    {
                        mutation++;
                    }
                    if (mutation > 1)
                        break;
                }
                if (mutation == 1)
                {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }

        if (endIndex == -1)
            return -1;

        queue<int> q;
        vector<bool> visited(n, false);
        int step = 1;

        for (int i = 0; i < n; i++)
        {
            int mutation = 0;
            for (int k = 0; k < m; k++)
            {
                if (bank[i][k] != start[k])
                {
                    mutation++;
                }
                if (mutation > 1)
                    break;
            }
            if (mutation == 1)
            {
                q.emplace(i);
                visited[i] = true;
            }
        }

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int curr = q.front();
                q.pop();
                if (curr == endIndex)
                    return step;
                for (auto &next : adj[curr])
                {
                    if (visited[next])
                        continue;
                    visited[next] = true;
                    q.emplace(next);
                }
            }
            step++;
        }
        return -1;
    }
};