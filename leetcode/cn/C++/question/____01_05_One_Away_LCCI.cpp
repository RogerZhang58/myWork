// @algorithm @lc id=1000006 lang=cpp
// @title one-away-lcci

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class Solution
{
public:
    bool oneEditAway(string first, string second)
    {
        int m = first.size(), n = second.size();
        if (m - n == 1 || n - m == 1)
        {
            if (m < n)
            {
                string tmp = second;
                second = first;
                first = tmp;
            }
            int i = 0, j = 0;
            while (i < first.size() && j < second.size())
            {
                if (first[i] == second[j])
                {
                    j++;
                }
                i++;
                if (i - j > 1)
                {
                    return false;
                }
            }
            return true;
        }
        else if (m == n)
        {
            int diff = 0;
            for (int i = 0; i < m; i++)
            {
                if (first[i] != second[i])
                {
                    diff++;
                    if (diff > 1)
                        return false;
                }
            }
            return true;
        }
        return false;
    }
};