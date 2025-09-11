#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

  if (i < 0 || j < 0 || (grid[i][j] == -1))
  {
    return 0;
  }

  if (dp[i][j] != -1)
    return dp[i][j];

  if (i == 0 && j == 0 && grid[i][j] != -1)
    return 1;
  int up = helper(i, j - 1, grid, dp);
  int left = helper(i - 1, j, grid, dp);
  return dp[i][j] = up + left;
}

int main()
{
  vector<vector<int>> grid = {
      {-1, 0, 0, 0, 0},
      {0, 0, -1, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
  };
  int n = grid.size();
  int m = grid[0].size();
  // vector<vector<int>> dp(n, vector<int> (m, -1));
  // cout<<endl<<helper(n-1, m-1, grid, dp);

  // tabulation:
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i >= 0 && j >= 0 && grid[i][j] == -1)
        dp[i][j] = 0;
      else if (i == 0 && j == 0 && dp[i][j] != -1)
        dp[i][j] = 1;
      else
      {
        int up = 0;
        int left = 0;
        if (j > 0)
          up = dp[i][j - 1];
        if (i > 0)
          left = dp[i - 1][j];
        dp[i][j] = up + left;
      }
    }
  }
  cout << endl
       << dp[n - 1][m - 1];
}