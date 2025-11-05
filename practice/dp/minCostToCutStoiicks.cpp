#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int helper(int i, int j, vector<int> &nums) {
  if (i > j) return 0;
  int mini = INT_MAX;
  for (int ind = i; ind <= j; ind++) {
    int cost = nums[j+1] - nums[i-1] + helper(i, ind-1, nums) + helper(ind+1, j, nums);
    mini = min(cost, mini);
  }
  return mini;
}

int main () {
  vector<int> nums = {1,3,5,7};
  int n = nums.size();
  nums.push_back(n);
  nums.insert(nums.begin(), 0);
  sort(nums.begin(), nums.end());
}