#include<iostream>
#include<vector>
using namespace std;

bool helper(int index, int n, int target, vector<int> &nums, vector<vector<int>> &dp) {
  if (target == 0) return true;
  if (index == 0) return nums[index] == target;

  if (dp[index][target] != -1) return dp[index][target];
  bool notPick = helper(index-1, n, target, nums, dp);

  bool pick = false;
  pick = helper(index-1, n, target - nums[index], nums, dp);

  return pick || notPick;
}


int main() {
  vector<int> nums = {2,3,3,3,4,5};
  int sum = 0;
  int n = nums.size();
  for (auto it: nums) {
    sum += it;
  }

  
  if (sum %2 != 0) return -1;
  int target = sum / 2;
  
  vector<vector<int>> dp(n, vector<int> (target+1, -1));
  cout<<endl<<helper(n-1, n, target, nums, dp);

}