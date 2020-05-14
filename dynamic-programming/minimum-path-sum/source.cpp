#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

      int vSide = grid.size();
      int hSide = grid[0].size();

      int dp[vSide][hSide];

      memset(dp, 0, sizeof(dp));

      // Set base case

      dp[0][0] = grid[0][0];

      int left, top;

      for(int y = 0; y < vSide; ++y)
        for(int x = 0; x < hSide; ++x) {
          left = INT_MAX, top = INT_MAX;

          if(y == 0 && x == 0)
            continue;

          if(y >= 1)
            top = dp[y-1][x];

          if(x >= 1)
            left = dp[y][x-1];

          dp[y][x] = min(top, left) + grid[y][x];

        }

      return dp[vSide - 1][hSide - 1];

    }
};

int main() {

  Solution solution;

  vector<vector<int>> grid{{1, 2, 5}, {3, 2, 1}};

  assert(solution.minPathSum(grid) == 6);

  return 0;
}
