#include <bits/stdc++.h>

using namespace std;

int cg() {

  vector<int> coins = {1, 2, 5};
  int amount = 11;

  int dp[amount + 1];

  memset(dp, -1, sizeof(dp));

  dp[0] = 0;

  for(int i = 1; i < amount + 1; ++i) {

    int m = INT_MAX;

    for(auto coin : coins)
      if(i - coin >= 0)
        if(dp[i-coin] != -1)
          if(m > dp[i - coin] + 1)
            m = dp[i - coin] + 1;

    if(m != INT_MAX)
      dp[i] = m;
  }

  return dp[amount];
}

int main() {
  cout << cg();

  return 0;
}
