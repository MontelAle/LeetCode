// https://leetcode.com/problems/maximum-product-subarray/
#include <bits/stdc++.h>

using namespace std;

int mps() {

  vector<int> nums = {-2, 3, -4};

  if (nums.size() == 1)
    return nums[0];

  // 0 is max so far, 1 is min so far

  int dp[2];

  memset(dp, 0, sizeof(dp));

  // set base case

  dp[0] = nums[0];
  dp[1] = nums[0];

  int ans = dp[0];

  for(int i = 1; i < nums.size(); ++i) {
    int mx = nums[i] * dp[0];
    int mn = nums[i] * dp[1];

    dp[0] = max({nums[i], mx , mn});
    dp[1] = min({nums[i], mx, mn});

    if(dp[0] > ans)
      ans = dp[0];
  }

  return ans;

}

int main() {

  cout << mps();

  return 0;

}
