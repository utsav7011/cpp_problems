#include<iostream>
#include<vector>
#include<set>
using namespace std;

void subsetSum (set<int> &ans, vector<int> &nums, int index, int n, int &sum) {
  if (index == n) {
    ans.insert(sum);
    return;
  }
  // include the nums[index]
  sum += nums[index];
  subsetSum(ans, nums, index+1, n, sum);
  sum -= nums[index];
  // exlude the nums[index]
  subsetSum(ans, nums, index+1, n, sum); 
}

int main() {
  vector<int> nums = {5,2,1};
  int sum = 0;
  set<int> ans;
  int index = 0;
  int n = nums.size();
  subsetSum(ans, nums, index, n, sum);
  for (auto it: ans) {
    cout << it << " ";
  }
}