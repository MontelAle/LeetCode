// https://leetcode.com/problems/minimum-falling-path-sum/
#include <bits/stdc++.h>

using namespace std;

int mfps() {

  vector<vector<int>> A = {{1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 }};

  int side = A.size();

  int dp[side][side];

  memset(dp, 0, sizeof(dp));

  // Set base cases (last row)
  for(int i = 0; i < side; ++i)
    dp[side - 1][i] = A[side - 1][i];

  for(int y = side - 2; y >= 0; --y)
    for(int x = 0; x < side; ++x) {

      dp[y][x] = INT_MAX;

      if(x > 0)
        dp[y][x] = min(dp[y][x], dp[y+1][x-1] + A[y][x]);

      if(x < side - 1)
        dp[y][x] = min(dp[y][x], dp[y + 1][x + 1] + A[y][x]);

      dp[y][x] = min(dp[y][x], dp[y + 1][x] + A[y][x]);
    }

  // for(int y = 0; y < side; ++y) {
  //   for(int x = 0; x < side; ++x)
  //     cout << dp[y][x] << " ";
  //   cout << endl;
  // }

  int ans = INT_MAX;

  for(int x = 0; x < side; ++x)
    if(dp[0][x] < ans)
      ans = dp[0][x];

  return ans;


}

int main() {

  mfps();

  return 0;

}
