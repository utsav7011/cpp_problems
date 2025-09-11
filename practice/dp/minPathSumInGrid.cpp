#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
    return grid[i][j];
  if (i < 0 || j < 0)
    return INT_MAX;
  if (dp[i][j] != -1) return dp[i][j];
  
  int up = grid[i][j] + helper(i - 1, j, grid, dp);
  int left = grid[i][j] + helper(i, j - 1, grid, dp);

  return dp[i][j] = min(up, left);
}

int main()
{
  vector<vector<int>> grid = {
      {1, 3, 1},
      {1, 5, 1},
      {4, 2, 1}};
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  cout << endl
       << helper(n - 1, m - 1, grid, dp);
}