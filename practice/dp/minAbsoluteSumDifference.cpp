#include<vector>
#include<iostream>
using namespace std;

int main() {
  
  vector<int> nums = {2,3,3,3,4,5};
  int n = nums.size();
  int sum = 0;
  for (auto it: nums) {
    sum += it;
  }
  
  vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));
  dp[0][nums[0]] = true;

  for (int i = 0;  i< n; i++) {
    dp[0][i] = true;
  }

  for (int index = 1; index < n; index++) {
    for (int t = 1; t <= sum; t++ ) {
      bool notTake = dp[index-1][t];
      bool take = false;
      if (t >= nums[index]) take = dp[index-1][t - nums[index]];
      dp[index][t] = take || notTake;
    }
  }
  int mini = INT_MAX;
  for (int i = 0;  i<= sum; i++) {
    if (dp[n-1][i]) {
      mini = min(mini, abs((sum - i) - i));
    }
  }
  cout<<endl<<mini;
}