#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Solution
{
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK)
  {
    long long count = 0;
    long long left = 0;
    int n = nums.size();
    deque<int> dq_min, dq_max;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] < minK || nums[i] > maxK)
      {
        dq_min.clear();
        dq_max.clear();
        left = i + 1;
        continue;
      }
      while (!dq_min.empty() && nums[dq_min.back()] >= nums[i])
        dq_min.pop_back();
      dq_min.push_back(i);

      while (!dq_max.empty() && nums[dq_max.back()] <= nums[i])
        dq_max.pop_back();
      dq_max.push_back(i);

      if (nums[dq_min.front()] == minK && nums[dq_max.front()] == maxK)
      {
        int start = min(dq_min.front(), dq_max.front());
        count += (start - left + 1);
      }
    }
    return count;
  }
};