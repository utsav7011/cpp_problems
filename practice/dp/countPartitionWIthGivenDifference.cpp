#include<iostream>
#include<vector>
using namespace std;

int MOD = 1e9+7;

bool helper (int index, int n, int target, vector<int>&nums ) {
  if (index == 0) {
    return nums[index] == target;
  }
  bool notPick = helper(index-1, n, target, nums);
  bool pick = false;
  if (nums[index] >= target) pick = helper(index-1, n, target - nums[index], nums);
  return pick || notPick;
}


int main() {
  vector<int> nums = {1,2,3,4,5};
  int n = nums.size();
  int diff = 3;
  int totalSum = 0;
  for (auto it: nums) totalSum += it;
  int s2 = (totalSum - diff) / 2;
  if ((totalSum - diff)  % 2 != 0) {
    cout<< -1;
    return 0;
  } 

  cout<<endl<<helper(n-1, n, s2, nums);
}