#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define MOD 1000000007
using namespace std;

/**
 * .....
 * ...*,
 * ...*.
 * ..*..
 * *....
 *
 *
 */

// movements:
// up, left

int helper(int i, int j, int n, vector<vector<int>> &dp, vector<vector<char>> grid)
{
  if (i == 0 && j == 0)
  {
    if (grid[i][j] == '.')
      return 1;
    return 0;
  }
  if (i < 0 || j < 0)
    return 0;
  if (grid[i][j] == '*')
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  // move in grid from bottom right to top left:
  int up = helper(i - 1, j, n, dp, grid);
  int left = helper(i, j - 1, n, dp, grid);

  return dp[i][j] = up + left;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n, '.'));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      char ele;
      cin >> ele;
      grid[i][j] = ele;
    }
  }

  // vector<vector<int>> dp(n, vector<int> (n, -1));
  // cout<<endl<<helper(n-1, n-1, n, dp, grid);

  vector<vector<int>> dp(n, vector<int>(n, 0));
  // Initialize first row
  for (int i = 0; i < n; i++)
  {
    if (grid[0][i] == '.')
    {
      dp[0][i] = (i == 0) ? 1 : dp[0][i - 1];
    }
    // if grid[0][i] == '*', dp[0][i] stays 0 and blocks further cells
  }

  // Initialize first column
  for (int i = 0; i < n; i++)
  {
    if (grid[i][0] == '.')
    {
      dp[i][0] = (i == 0) ? 1 : dp[i - 1][0];
    }
    // if grid[i][0] == '*', dp[i][0] stays 0 and blocks further cells
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      int up = 0, left = 0;
      if (grid[i][j] != '*')
      {
        up = dp[i - 1][j];
        left = dp[i][j - 1];
      }
      dp[i][j] = (up + left) % MOD;
    }
  }
  cout << dp[n - 1][n - 1];
}