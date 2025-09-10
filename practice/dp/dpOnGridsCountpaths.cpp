#include <iostream>
using namespace std;

int helper(int i, int j, int n, int m, vector<vector<int>> &dp)
{
  if (i < 0 || j < 0)
    return 0;
  if (i == 0 && j == 0)
  {
    return 1;
  }
  if (dp[i][j] != -1)
    return dp[i][j];
  int up = 0;
  if (i - 1 >= 0)
  {
    up = helper(i - 1, j, n, m, dp);
  }
  int left = 0;
  if (j + 1 >= 0)
  {
    left = helper(i, j - 1, n, m, dp);
  }
  return dp[i][j] = up + left;
}

int main()
{
  int n = 4;
  int m = 3;
  // vector<vector<int>> dp(n, vector<int>(m, -1));
  // cout << endl
  //      << helper(n - 1, m - 1, n, m, dp);

  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int up = 0;
      int left = 0;
      if (i == 0 && j == 0)
      {
        dp[0][0] = 1;
        break;
      }
      if (i > 0)
        left = dp[i - 1][j];
      if (j > 0)
        up = dp[i][j - 1];
      dp[i][j] = up + left;
    }
  }

  for (auto it: dp) {
    for (auto ele: it) cout<<ele<<" ";
    cout<<endl;
  }
  cout << dp[n - 1][m - 1];
}