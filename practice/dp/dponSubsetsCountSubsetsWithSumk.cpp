#include<iostream>
#include<vector>
using namespace std;

int helper(int index, int n, int target, vector<int> &nums, vector<vector<int>> &dp) {
  if (target == 0) return 1;
  if (index == 0) {
    return nums[index] == target;
  }
  if (dp[index][target] != -1) return dp[index][target];
  int notTake = helper(index-1, n, target, nums, dp);
  int take = 0;
  if (nums[index] <= target) take = helper(index-1, n, target - nums[index], nums, dp);
  return dp[index][target] = take + notTake;
}

int main() {
  vector<int> nums = {1,2,2,3};
  int n = 4;
  int target = 3;
  vector<vector<int>> dp(n, vector<int> (target+1, -1));
  cout<<endl<<helper(n-1, n, target, nums, dp);
}