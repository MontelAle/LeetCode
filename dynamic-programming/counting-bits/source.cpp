// https://leetcode.com/problems/counting-bits/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> dp(num + 1);

    for (int i = 1; i < num + 1; ++i) {
      if (i % 2 == 0)
        dp[i] = dp[i / 2];
      else
        dp[i] = dp[i - 1] + 1;
    }

    return dp;
  }
};

int main() {

  Solution solution;

  vector<int> expected = {0, 1, 1};

  assert(solution.countBits(2) == expected);

  return 0;
}
