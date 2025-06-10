#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

void infixToPostfix(string s, string &ans, unordered_map<char, int> priority) {
  stack<char> st;
  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    if (isalnum(ch)) {
      ans += ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      if (!st.empty()) st.pop(); // pop '('
    } else {
      while (!st.empty() && st.top() != '(' && priority[ch] <= priority[st.top()]) {
        ans += st.top();
        st.pop();
      }
      st.push(ch);
    }
  }

  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
}

int main () {
  string str = "a+b*(c^d-e)";
  string ans = "";
  unordered_map<char, int> priority = {{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
  infixToPostfix(str, ans, priority);
  cout << "Infix:   " << str << endl;
  cout << "Postfix: " << ans << endl;
}
