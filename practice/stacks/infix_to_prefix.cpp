// infix to prefix
// reverse the string
// convert the open to closing bracket and closing to opening bracket.

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int getPriority (char op) {
  if (op == '^') return 3;
  else if (op == '*' || op == '/') return 2;
  else if (op == '+' || op == '-') return 1;
  else return -1;
}

void convertInfixToPrefix(string str, string &ans) {
  int i = 0;
  int n = str.size();
  stack<int> st;
  reverse(str.begin(), str.end());
  
  for (int i  = 0; i < n; i++) {
    if (str[i] == '(') str[i] = ')';
    if (str[i] == ')') str[i] = '(';
  }

  while (i < n) {
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
      ans += str[i];
    }
    if (str[i] == '(') st.push(str[i]);
    else if (str[i] == ')') {
      while (!st.empty() && str[i] != '(') {
        ans += st.top();
        st.pop();
      }
      if (!st.empty()) st.pop();
    } else if (st.empty() || getPriority(str[i]) >= getPriority(st.top())) {
      st.push(str[i]);
    } else if (getPriority(str[i]) < getPriority(st.top())) {
      while (!st.empty() && getPriority(st.top()) > getPriority(str[i])) {
        ans += st.top();
        st.pop();
      }
      st.push(str[i]);
    }
    i++;
  }
  reverse(ans.begin(), ans.end());
}

int main() {
  string inputStr = "a+b*(c^d-e)", ans = "";
  convertInfixToPrefix(inputStr, ans);
  cout<<endl<<"infix" << inputStr;
  cout<<endl<<"prefix: "<<ans;
}