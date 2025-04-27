#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int search(vector<int>& nums, int target) {
          if (nums.size() == 1 && nums[0] == target) return 0;
          int i = 0;
          int j = nums.size() - 1;
          int index = -1;
          while (i <= j) {
              int mid = (i + j) / 2;
              if (nums[mid] == target) {
                  index = mid;
                  break;
              } else if (nums[mid] > target) {
                  j = mid - 1;
              } else {
                  i = mid + 1;
              }
          }
          return index;
      }
  };