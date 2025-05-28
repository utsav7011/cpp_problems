#include <stack>
#include <iostream>
#include <vector>
using namespace std;

void insertStack(stack<int> &st, int ele) {
  if (st.empty() || st.top() >= ele) {
    st.push(ele);
    return;
  }
  int temp = st.top();
  st.pop();
  insertStack(st, ele);
  st.push(temp);
  return;
}

void sortStack(stack<int> &st) {
  if (st.empty()) {
    return;
  }
  int ele = st.top();
  st.pop();
  sortStack(st);
  insertStack(st, ele);
}


int main() {
  vector<int> nums = {1,4,3,2,5};
  stack<int> st;
  for (auto it: nums) {
    st.push(it);
  }
  sortStack(st);
  while (!st.empty()) {
    cout<<st.top();
    st.pop();
  }
}