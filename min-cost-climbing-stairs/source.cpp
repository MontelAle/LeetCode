// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <bits/stdc++.h>

using namespace std;

int msc() {

    vector<int> cost = {0, 0, 0, 1};

    cost.push_back(0);

    vector<int> dp(cost.size());

    // Setting base cases (first and second step in dp)
    for(int i = 0; i <= 1; ++i)
        dp[i] = cost[i];

    for(int i = 2; i < dp.size(); ++i) {
        int m = INT_MAX;

        for (int j = i - 2; j < i; ++j)
            if (dp[j] < m)
                m = dp[j];

        dp[i] = m + cost[i];
    }

    // for (auto x : dp)
    //     cout << x << " ";

    // cout << dp[cost.size() - 1];

    return dp[cost.size() - 1];



}

int main() {

    msc();

    return 0;

}
