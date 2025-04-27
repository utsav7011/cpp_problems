// Given a sorted array of distinct integers and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int lower_bound(vector<int> &nums, int left, int right, int target, int ansIndex)
  {
    if (left > right)
      return ansIndex;
    int mid = left + (right - left) / 2;
    if (nums[mid] >= target)
    {
      ansIndex = mid;
      return lower_bound(nums, left, mid - 1, target, ansIndex);
    }
    else
    {
      return lower_bound(nums, mid + 1, right, target, ansIndex);
    }
  }
  int searchInsert(vector<int> &nums, int target)
  {
    int ansIndex = lower_bound(nums, 0, nums.size() - 1, target, -1);
    if (ansIndex == -1)
      return nums.size();
    return ansIndex;
  }
};