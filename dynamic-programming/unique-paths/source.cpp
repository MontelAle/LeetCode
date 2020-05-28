// https://leetcode.com/problems/unique-paths/submissions/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

      int dp[n][m];

      memset(dp, 0, sizeof(dp));

      dp[0][0] = 1;

      for(int y = 0; y < n; ++y)
        for(int x = 0; x < m; ++x) {
          if(x > 0)
            dp[y][x] += dp[y][x-1];
          if(y > 0)
            dp[y][x] += dp[y-1][x];
        }

      return dp[n-1][m-1];

    }
};

int main() {

  Solution solution;

  int m = 3, n = 2;

  assert(solution.uniquePaths(m, n) == 3);

  return 0;

}
