#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
  if (j < 0 || j >= m)
    return INT_MAX;
  if (i == 0)
    return grid[i][j];
  if (dp[i][j] != -1)
    return dp[i][j];
  // move up;
  int up = grid[i][j] + helper(i - 1, j, n, m, grid, dp);
  // move top left diag
  int topLeftDiag = grid[i][j] + helper(i - 1, j - 1, n, m, grid, dp);
  // move top right diag;
  int topRigthDiag = grid[i][j] + helper(i - 1, j + 1, n, m, grid, dp);

  return dp[i][j] = max(up, max(topLeftDiag, topRigthDiag));
}

int main()
{
  vector<vector<int>> grid = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
  int n = grid.size();
  int m = grid[0].size();
  int mini = INT_MIN;
  for (int j = 0; j < m; j++)
  {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int val = helper(n - 1, j, n, m, grid, dp);
    mini = max(mini, val);

    for (auto it : dp)
    {
      for (auto ele : it)
      {
        cout << ele << " ";
      }
      cout << endl;
    }
    cout<<endl<<endl;
  }
  cout << endl
       << mini;
}