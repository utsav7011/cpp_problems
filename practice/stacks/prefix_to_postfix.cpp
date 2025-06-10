#include<vector>
#include<iostream>
#include<stack>
using namespace std;

void prefixToPostfix (string prefix, string &postfix){
  stack<string> st;
  for (int i = prefix.size()-1;  i >= 0; i--) {
    string s = "";
    if ((prefix[i] >= 'A' && prefix[i] <= 'Z') || (prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= '0' && prefix[i] <= '9')) {
      s.push_back(prefix[i]);
      st.push(s);
    } else {
      string firstOperand = st.top();
      st.pop();
      string secondOperand = st.top();
      st.pop();
      string expression = firstOperand + secondOperand + prefix[i];
      st.push(expression);
    }
  }
  postfix = st.top();
  st.pop();
}

int main() {
  string prefix = "/-AB*+DEF";
  string postfix = "";
  prefixToPostfix(prefix, postfix);
  cout<<endl<<postfix;
}