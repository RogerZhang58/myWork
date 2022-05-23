// @algorithm @lc id=990 lang=cpp
// @title verifying-an-alien-dictionary

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(["hello","leetcode"],"hlabcdefgijkmnopqrstuvwxyz")=true
// @test(["word","world","row"],"worldabcefghijkmnpqstuvxyz")=false
// @test(["apple","app"],"abcdefghijklmnopqrstuvwxyz")=false
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int index[26];
        for (int i = 0; i < 26; i++)
        {
            index[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++)
        {
            bool valid = false;
            for (int j = 0; j < words[i].size() && j < words[i - 1].size(); j++)
            {
                if (index[words[i][j] - 'a'] > index[words[i - 1][j] - 'a'])
                {
                    valid = true;
                    break;
                }
                else if (index[words[i][j] - 'a'] < index[words[i - 1][j] - 'a'])
                {
                    return false;
                }
            }
            if (!valid)
            {
                if (words[i].size() < words[i - 1].size())
                    return false;
            }
        }
        return true;
    }
};