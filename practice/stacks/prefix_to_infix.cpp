#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void prefixToinfix(string str, string &ans) {
  stack<string> st;
  for (int i = str.size()-1; i >= 0; i--) {
    string s = "";
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
      s.push_back(str[i]);
      st.push(s);
    } else {
      string firstOperand = st.top();
      st.pop();
      string secondOperand = st.top();
      st.pop();
      string expression = "(" + firstOperand + str[i] + secondOperand + ")";
      st.push(expression);
    }
  }
  ans = st.top();
  st.pop();
}

int main() {
  string str = "/+abc";
  string ans = "";
  prefixToinfix(str, ans);
  cout<<endl<<ans;
}