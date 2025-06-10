#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    void combinationSum(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int index) {
      if (n == 0) {
        if (temp.size() == k) ans.push_back(temp);
        return;
      }
      if (index > n || n < 0 || index < 1 || index > 9) return;
      // call with index
      temp.push_back(index);
      combinationSum(ans, temp, k, n - index, index + 1);
      temp.pop_back();
      // call without sum
      combinationSum(ans, temp, k, n, index+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum(ans, temp, k, n, 1);
        return ans;
    }
};