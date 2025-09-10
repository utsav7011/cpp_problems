#include <vector>
#include <iostream>
using namespace std;

int helper(int index, vector<int> &nums, vector<int> &dp)
{
  if (index < 0)
    return 0;
  if (index == 0)
    return nums[index];
  if (dp[index] != -1)
    return dp[index];
  int pick = INT_MIN;
  if (index > 1)
    pick = nums[index] + helper(index - 2, nums, dp);
  int notPick = helper(index - 1, nums, dp);
  return dp[index] = max(pick, notPick);
}

int main()
{
  int n = 5;
  vector<int> nums = {10, 20, 30, 40, 60};
  int sum = 0;
  // vector<int> dp(n, -1);
  // int maxSum = helper(n - 1, nums, dp);
  // cout << endl
  //      << maxSum;
  // vector<int> dp(n + 1, 0);
  // dp[0] = nums[0];

  int prev = nums[0];
  int prev2 = 0;
  for (int i = 1; i < n; i++)
  {
    int pick = i > 1 ? nums[i] + prev2 : INT_MIN;
    int notPick = prev;
    int curr = max(pick, notPick);
    prev2 = prev;
    prev = curr;
  }
  cout << endl
       << prev;
}