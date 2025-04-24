#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
  public:
      int countCompleteSubarrays(vector<int>& nums, int left = 0, int res = 0) {
          int k = unordered_set<int>(nums.begin(),nums.end()).size();
          unordered_map<int, int> mpp;
  
          for (int i = 0; i < nums.size(); ++i) {
              mpp[nums[i]]++;
              while (mpp.size() == k) {
                  res += nums.size() - i;  
                  mpp[nums[left]]--;
                  if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                  left++;
              }
          }
          return res;
      }
  };