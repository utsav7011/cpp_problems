#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int binarySearch(vector<int> &nums, int start, int end, int target)
  {
    if (start > end)
      return -1;

    int mid = (start + end) / 2;

    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target)
    {
      return binarySearch(nums, start, mid - 1, target);
    }
    else
    {
      return binarySearch(nums, mid + 1, end, target);
    }
  }
  int search(vector<int> &nums, int target)
  {
    return binarySearch(nums, 0, nums.size() - 1, target);
  }
};