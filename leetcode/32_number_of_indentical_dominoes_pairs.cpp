#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
  public:
      int numEquivDominoPairs(vector<vector<int>>& dominoes) {
          int count = 0;
          map<pair<int, int>, int> mpp;
          for (auto it: dominoes) {
              if (it[0] > it[1]) swap(it[0], it[1]);
              mpp[{it[0], it[1]}]+=1;
          }
  
          for (auto it: mpp) {
              count += it.second * (it.second-1) / 2;
          }
          return count;
      }
  };