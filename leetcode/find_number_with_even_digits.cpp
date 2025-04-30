#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

class Solution {
  public:
      int findNumbers(vector<int>& nums) {
          int count = 0;
          for (auto it: nums) {
              string str = to_string(it);
              if (str.length()%2 == 0) count++;
          }
          return count;
      }
  };