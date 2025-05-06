#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  vector<int> buildArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
      ans[i] = nums[nums[i]];
    }
    return ans;
  }
};