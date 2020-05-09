// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int dp[amount + 1];

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for (int i = 1; i < amount + 1; ++i) {

      int m = INT_MAX;

      for (auto coin : coins)
        if (i - coin >= 0)
          if (dp[i - coin] != -1)
            if (m > dp[i - coin] + 1)
              m = dp[i - coin] + 1;

      if (m != INT_MAX)
        dp[i] = m;
    }

    return dp[amount];
  }
};

int main() {

  Solution solution;

  vector<int> coins = {1, 2, 5};

  assert(solution.coinChange(coins, 11) == 3);

  return 0;
}
