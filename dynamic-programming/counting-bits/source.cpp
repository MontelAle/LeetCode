// https://leetcode.com/problems/counting-bits/

#include <bits/stdc++.h>

using namespace std;

vector<int> cb() {

  int num = 5;

  vector<int> dp(num + 1);

  for(int i = 1; i < num + 1; ++i) {
    if(i%2==0)
      dp[i] = dp[i/2];
    else
      dp[i] = dp[i-1] + 1;
  }

  return dp;

}

int main() {

  cb();

  return 0;

}
