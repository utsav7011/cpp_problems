#include<iostream>
#include<vector>
using namespace std;

int helper(int index, int n, int sum, int target, vector<int> &nums) {
  if (target == sum) return 1;
  if (index == 0) {
    if (nums[0] + sum == target || sum - nums[0] == target) return 1;
    return false; 
  } 

  int pickPositive = helper(index-1, n, sum + nums[index], target, nums);
  int pickNegative = helper(index-1, n, sum - nums[index], target, nums);
  return pickPositive + pickNegative;
}

int main() {
  vector<int> nums = {1,2,3,4,5};
  int target = 10;
  int n = nums.size();
  cout<<endl<<helper(n-1, n, 0, target, nums);

}