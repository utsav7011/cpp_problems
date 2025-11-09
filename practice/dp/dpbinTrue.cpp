#include<iostream>
using namespace std;

int helper(int i, int j, bool isTrue, string str) {
  if (i > j) return 0;
  if (i == j) {
    if (isTrue) return str[i] == 'T';
    else return str[i] == 'F';
  }
  int ways = 0;
  for (int k = i+1; k <= j-1; k++) {
    int leftTrue = helper(i, k-1, 1, str );
    int leftFalse = helper(i, k-1, 0, str);
    int rightTrue = helper(k+1, j, 1, str);
    int rightFalse = helper(k+1, j, 0, str);

    if (str[k] == '&') {
      if (isTrue) ways += leftTrue * rightTrue;
      else ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
    } else if (str[k] == '|') {
      if (isTrue) ways += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
      else ways += (leftFalse * rightFalse);
    } else if (str[k] == '^') {
      if (isTrue) ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
      else ways += (leftTrue * rightTrue) + (leftFalse * rightFalse);
    }
  }
  return ways;
}

int main() {
  string str = "T^F|T&F^T|F";
  int len = str.length();
  cout<<endl<<helper(1, len, true, str);
}