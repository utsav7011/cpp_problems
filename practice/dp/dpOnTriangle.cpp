
#include <iostream>
using namespace std;

int helper(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) {
  if (i == n-1) return grid[i][j];
  if (dp[i][j] != -1) return dp[i][j];

  int down = grid[i][j] + helper(i+1, j, n, grid, dp);
  int right = grid[i][j] + helper(i+1, j+1, n, grid, dp);

  return dp[i][j] = min(down, right);
}

int main()
{
  vector<vector<int>> grid = {{1, 0, 0, 0}, {2, 3, 0, 0}, {3, 6, 7, 0}, {8, 9, 6, 10}};
  int n = grid.size();
  int m = grid[n-1].size();
  // vector<vector<int>> dp(n, vector<int> (m, -1));
  // cout<<endl<<helper(0, 0, n, grid, dp);


  vector<vector<int>> dp(n, vector<int> (m, 0));
  dp[0][0] = grid[0][0];

  for (int i = 1;  i< n; i++) {
    for (int j = 0; j < m; j++) {
      int up = grid[i][j] + dp[i][j-1];
      int diag = INT_MAX;
      if (j > 0) diag = grid[i][j] + dp[i-1][j-1];
      dp[i][j] = min(up, diag);
    }
  }

  int mini = INT_MAX;
  for (auto it: dp[n-1]) {
    cout<<it<<" ";
    mini = min(it, mini); 
  }
  cout<<endl<<mini;
}