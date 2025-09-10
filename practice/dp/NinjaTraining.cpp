#include <iostream>
#include <vector>
using namespace std;

int helper(int index, int n, int lastActivity, vector<vector<int>> &points, vector<vector<int>> &dp)
{
  if (index == 0)
  {
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
      if (i != lastActivity)
        maxi = max(maxi, points[0][i]);
    }
    return maxi;
  }
  if (dp[index][lastActivity] != -1)
    return dp[index][lastActivity];
  int maxi = 0;
  for (int i = 0; i < 3; i++)
  {
    if (i != lastActivity)
    {
      int pointTally = points[index][i] + helper(index - 1, n, i, points, dp);
      maxi = max(maxi, pointTally);
    }
  }
  return dp[index][lastActivity] = maxi;
}

int main()
{
  int n = 3;
  vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
  // // Memoization:
  // vector<vector<int>> dp(n, vector<int> (4, -1));
  // cout << endl
  //      << helper(n - 1, n, 3, points, dp);

  // Tabulation:
  vector<vector<int>> dp(n, vector<int>(4, 0));
  dp[0][0] = max(dp[0][1], dp[0][2]);
  dp[0][1] = max(dp[0][0], dp[0][2]);
  dp[0][2] = max(dp[0][0], dp[0][1]);
  dp[0][3] = max(dp[0][1], max(dp[0][2], dp[0][3]));

  for (int i = 0; i < n; i++) {
    for (int lastActivity = 0; lastActivity < 4; lastActivity++) {
      dp[i][lastActivity] = 0;
      for (int k = 0; k <= 3; k++) {
        if (k != lastActivity) {
          int point = points[i][k] + dp[i-1][k];
          dp[i][lastActivity] = max(dp[i][lastActivity], point);
        }
      }
    }
  }

  cout<<dp[n-1][3];
}