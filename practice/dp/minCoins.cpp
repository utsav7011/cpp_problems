#include<iostream>
#include<vector>
using namespace std;

int helper(int index, int target, int n, vector<int> &nums, vector<vector<int>> &dp) {
  if (target == 0) return 0;
  if (index == 0) {
    if (target % nums[index] == 0) return target / nums[index];
    return 0;
  }
  if (dp[index][target] !=-1) return dp[index][target];
  int notTake = helper(index-1, target, n, nums, dp);
  int take = INT_MAX;
  if (target >= nums[index]) {
    take = 1 + helper(index, target - nums[index], n, nums, dp);
  }
  return dp[index][target] = min(take, notTake);
}

int main() {
  vector<int> coins = {1,2,3,4,5,6,7,8,9};
  int target = 11;
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int> (target+1, -1));
  cout<<endl<<helper(n-1, target, n, coins, dp);
}