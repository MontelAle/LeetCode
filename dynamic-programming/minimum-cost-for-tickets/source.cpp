// https://leetcode.com/problems/minimum-cost-for-tickets/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

      // Initialize dp and sd
      int dp[365];
      int sd[365];

      memset(dp, 0, sizeof(dp));
      memset(sd, 0, sizeof(sd));

      // Simplify everything to start at 0
      for(int i = 1; i < days.size(); ++i)
        days[i] = days[i] - days[0];

      days[0] = 0;

      // Put all of the days into a simple array of 365 0s and 1s
      for(auto x : days)
        sd[x] = 1;

      // Set dp base case
      dp[0] = costs[0];

      int oneDay, sevenDays, thirtyDays;

      for (int i = 0; i < 365; ++i) {
        if(sd[i] == 0) {
          dp[i] = dp[i - 1];
          continue;
        }

        oneDay = 0, sevenDays = 0, thirtyDays = 0;

        if(i >= 1)
          oneDay = dp[i - 1];

        if (i >= 7)
          sevenDays = dp[i - 7];

        if(i >= 30)
          thirtyDays = dp[i - 30];

        dp[i] = min({oneDay + costs[0], sevenDays + costs[1], thirtyDays + costs[2]});
      }

      return dp[364];

    }
};

int main() {

  Solution solution;

  vector<int> days = {1, 4, 6, 7, 8, 20};
  vector<int> costs = {2, 7, 15};

  assert(solution.mincostTickets(days, costs) == 11);

  return 0;
}
