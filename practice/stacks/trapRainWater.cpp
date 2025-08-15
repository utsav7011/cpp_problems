#include<vector>
#include<iostream>
using namespace std;

void trapWater(vector<int> &nums, int n, vector<int> &ans) {
  stack<int> rightMax, leftMax;
  vector<int> temp_right (n, -1);
  vector<int> temp_left (n, -1);

  for (int i = n-1; i >= 0; i--) {
    while (!rightMax.empty() && rightMax.top() <= nums[i]) rightMax.pop();
    if (rightMax.empty()) rightMax.push(-1);
    temp_right[i] = rightMax.top();
    rightMax.push(nums[i]);
  }

  for (int i = 0;  i< n; i++) {
    while (!leftMax.empty() && leftMax.top() >= nums[i]) leftMax.pop();
    if (leftMax.empty()) leftMax.push(-1);
    temp_left[i] = leftMax.top();
    leftMax.push(nums[i]);
  }

}

int main() {}