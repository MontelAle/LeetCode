// https://leetcode.com/problems/climbing-stairs/submissions/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int dp[n];

    if (n == 1)
      return 1;

    if (n == 2)
      return 2;

    // Initialize 2 base cases

    for (int i = 0; i <= 1; ++i)
      dp[i] = i + 1;

    for (int i = 2; i < n; ++i)
      dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n - 1];
  }
};

int main() {

  Solution solution;

  assert(solution.climbStairs(2) == 2);

  return 0;
}
