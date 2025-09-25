#include<iostream>
#include<vector>
using namespace std;

int helper(int index, int n, int target, vector<int> &nums, vector<vector<int>> &dp) {
    if (target == 0) return true;
    if (index == 0) return nums[0] == target;       
    
    if (dp[index][target] != -1) return dp[index][target];

    // not pick
    bool notpick = helper(index - 1, n, target, nums, dp);

    // pick
    bool pick = false;
    if (target >= nums[index]) 
        pick = helper(index - 1, n, target - nums[index], nums, dp);

    return dp[index][target] = pick || notpick;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int target = 5;
    // vector<vector<int>> dp(nums.size(), vector<int> (target+1, -1));
    // cout << endl << helper(nums.size()-1, nums.size(), target, nums, dp);

    vector<vector<bool>> dp(nums.size(), vector<bool> (target+1, 0));
    dp[0][nums[0]] = true;
    for (int i = 0; i < nums.size(); i++) dp[i][0] = true;
    for (int index = 1; index < nums.size(); index++) {
      for (int t = 1; t <= target; t++) {
        bool notTake = dp[index-1][t];
        bool take = false;
        if (t >= nums[index]) take = dp[index-1][t - nums[index]];
        dp[index][t] = take | notTake;
      }
    }

    for (auto it: dp) {
      for (auto ele: it) cout<<ele<<" ";
      cout<<endl;
    }

    cout<<dp[nums.size()-1][target];
}
