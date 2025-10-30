#include<iostream>
using namespace std;

int helper(int index, int n, int lastPick, vector<int> &nums) {
  if (index < 0) return 0;
  int len = 0 + helper(index-1, n, lastPick, nums);
  if (nums[index] < nums[lastPick]) {
    len = max(len, helper(index-1, n, index, nums));
  }
  return len;
}

int main() {
  vector<int> nums = {10, 9, 2, 5, 3,7,101, 18};
  int n = nums.size();
  
}