#include<iostream>
#include<stack>
#include<string>
using namespace std;

void postfixToPrefix (string str, string &ans ) {
  stack<string> st;
  for (int i = 0;  i< str.size(); i++) {
    string s = "";
    if ((str[i] >= 'A' && str[i] <= 'Z') | (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
      s.push_back(str[i]);
      st.push(s);
    } else {
      string secondOperand = st.top();st.pop();
      string firstOperand = st.top();st.pop();
      string expression = str[i] + firstOperand + secondOperand;
      st.push(expression);
    }
  }
  ans = st.top();
  st.pop();
}

int main() {
  string str = "ab-de+f*/";
  string ans = "";
  postfixToPrefix(str, ans);
  cout<<endl<<ans;
}