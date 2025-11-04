#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int helper(int index,int n, vector<int> &nums, vector<int> &picked) {
  if (index >= n) return 0;
  int len = helper(index+1, n, nums, picked);

  if (picked.empty() || nums[index] % picked.back() == 0) {
    picked.push_back(nums[index]);
    len = max(1 + helper(index+1, n, nums, picked), len);
  }
  return len;
}

int main () {
  vector<int> nums = {1,16,7,8,4};
  int n  = nums.size();
  vector<int> picked = {};
  sort(nums.begin(), nums.end());
  cout<<endl<<endl<<helper(0, n, nums, picked);
}