#include <iostream>
using namespace std;

bool targetSubsequence(int index, int n, int target, vector<int> &nums, vector<vector<int>> &dp)
{
  if (target == 0)
    return true;
  if (index == n)
  {
    if (target == 0)
      return true;
    return false;
  }

  if (dp[index][target] != -1)
    return dp[index][target];
  bool notTake = targetSubsequence(index - 1, n, target - nums[index], nums, dp);
  bool take = false;
  if (target >= nums[index])
  {
    take = targetSubsequence(index - 1, n, target - nums[index], nums, dp);
  }
  cout<<index<<"index"<<target<<endl;
  return dp[index][target] = take || notTake;
}

int main()
{
  int n = 4;
  vector<int> nums = {1, 2, 3, 4};
  int target = 4;
  vector<vector<int>> dp(10000, vector<int>(10000, -1));
  cout << endl
       << targetSubsequence(n - 1, n, target, nums, dp);
  // vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, 0));
  // for (int j = 0; j <= target; j++)
  // {
  //   dp[0][j] = true;
  // }
  // dp[0][nums[0]] = true;
  // for (int i = 1; i <= nums.size(); i++){
  //   for (int j = 1; j < target; j++) {
  //     bool pick = false;
  //     if (j > 0) {
  //       pick = dp[i-1][j - nums[i]];
  //     }
  //     bool notPick = dp[i-1][j];
  //     dp[i][j] = pick || notPick;
  //   }
  // }
  // for (auto it: dp) {
  //   for (auto ele: it) cout<<" "<<ele;
  //   cout<<endl;
  // }
}