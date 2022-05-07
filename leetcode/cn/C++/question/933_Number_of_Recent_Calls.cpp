// @algorithm @lc id=969 lang=cpp
// @title number-of-recent-calls
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;

class RecentCounter
{
private:
    queue<int> counters;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        counters.push(t);
        while (counters.front() < t - 3000)
        {
            counters.pop();
        }
        return counters.size();
    }
};