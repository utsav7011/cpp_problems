#include<set>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void helper(int row, int col, int n, int m, vector<vector<char>> nums, string &str, vector<string> &temp) {
  if (row == n-1 && col == n-1) {
    str.push_back(nums[row][col]);
    temp.push_back(str);
    str.pop_back();
    return;
  }

  if (row == n && col != n) return;
  if (row != n && col == n) return;

  if (row < n) {
    str.push_back(nums[row][col]);
    helper(row+1, col, n, m, nums, str, temp);
    str.pop_back();
  }
  if (col < n) {
    str.push_back(nums[row][col]);
    helper(row, col+1, n, m, nums, str, temp);
    str.pop_back();
  }
}


int main () {
  int n;
  cin>>n;
  vector<vector<char>> nums(n, vector<char> (n, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char ele;
      cin>>ele;
      nums[i][j] = ele;
    }
  }
  vector<string> temp;
  string str;
  helper(0, 0, n, n, nums, str, temp);
  
  sort(temp.begin(), temp.end());
  
  cout<<endl<<temp[0];
}