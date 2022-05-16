// @algorithm @lc id=979 lang=cpp
// @title di-string-match

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("IDID")=[0,4,1,3,2]
// @test("III")=[0,1,2,3]
// @test("DDI")=[3,2,0,1]
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        vector<int> perm(n + 1);
        int low = 0, high = n;
        for (int i = 0; i <= n; i++)
        {
            perm[i] = s[i] == 'I' ? low++ : high--;
        }
        perm[n] = low;
        return perm;
    }
};