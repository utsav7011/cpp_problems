#include<iostream>
using namespace std;

void nextGreaterEle (vector<int> &nums, int n, vector<int> &ans) {
  stack<int> st;
  for (int i = n-1; i >= 0; i--) {
    while (!st.empty() && st.top() <= nums[i]) {
      st.pop();
    }
    if (st.empty()) st.push(-1);
    ans[i] = st.top();
    st.push(nums[i]);
  }
}

int main() {
  vector<int> nums = {5,4,1,6,7};
  int n = nums.size();
  vector<int> ans (n, -1);
  nextGreaterEle(nums, n, ans);
  for (auto it: ans) {
    cout<<it<<" ";
  } 
}