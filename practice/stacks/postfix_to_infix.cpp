#include<iostream>
#include<string>
#include<stack>
using namespace std;

void postfixToInfix (string str, int index, string &ans) {

  stack<string> st;
  for (int i = 0;  i< str.size(); i++) {
    string s = "";
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9' ) ) {
      s.push_back(str[i]);
      st.push(s);
    }
    else {
        string secondOperand = st.top();
        st.pop();
        string firstOperand = st.top();
        st.pop();
        string expression = "(" + firstOperand + str[i] + secondOperand +  ")";
        st.push(expression);
    }
  }
  if (!st.empty()) {
    ans = st.top();
    st.pop();
  }
}

int main() {
  string str = "ab+c/", ans = "";
  postfixToInfix(str, 0, ans);
  cout<<endl<<ans;
}