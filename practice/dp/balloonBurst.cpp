#include<iostream>
using namespace std;

/**
 * 
 * points = 
 * 
 */

int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
  if (i > j) return 0;
  
  if (dp[i][j] != -1) return dp[i][j];

  int maxi = INT_MIN;
  for (int k = i; k <= j; k++) {
    int points = nums[i-1]*nums[k]*nums[j+1] + helper(i, k-1, nums, dp) + helper(k+1, j, nums, dp);
    maxi = max(maxi, points);
  }
  return dp[i][j] = maxi;
 }
int main () {
  vector<int> nums = {3,1,5,8};
  int n = nums.size();
  nums.push_back(1);
  nums.insert(nums.begin(), 1);
  vector<vector<int>> dp(n+1, vector<int> (n+2, -1));
  cout<<endl<<helper(1, n, nums, dp);
}