#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void reverseStack(stack<int> &st) {
  if (st.empty())
    return;
  int ele = st.top();
  st.pop();
  reverseStack(st);
  st.push(ele);
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  stack<int> st;
  for (auto it : nums)
  {
    st.push(it);
  }
  reverseStack(st);
  while (!st.empty())
  {
    cout << st.top();
    st.pop();
  }
}