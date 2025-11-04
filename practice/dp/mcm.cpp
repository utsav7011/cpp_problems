#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int helperMcm(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
  if (i == j) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int mini = INT_MAX;
  for (int k = i; k < j; k++) {
    int steps = (nums[i-1] * nums[k] * nums[j]) + helperMcm(i, k, nums, dp) + helperMcm(k+1, j ,nums, dp);
    mini = min(mini, steps);
  }
  return dp[i][j] = mini;
}

int main() {
  vector<int> nums = {10, 20, 30, 40, 50};
  int n = nums.size();
  vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
  cout<<endl<<helperMcm(1, n-1, nums, dp);
}