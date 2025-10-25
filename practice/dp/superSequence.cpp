// Wiildcard matching.....

#include<iostream>
using namespace std;

int helper(int i, int j, int n, int m, string str1, string str2) {
  if (i < 0 && j < 0) return true;
  if (i < 0) return false;

  if (str1[i-1] == str2[j-1] || str2[j-1] == '?') {
    return 1 + helper(i-1, j-1, n, m, str1, str2);
  } else if (str2[j-1] == '*') {
    // either consider a * to be something or consider it to be an empty sequence: 
    return helper(i-1, j, n, m, str1, str2) + helper(i, j-1, n,m , str1, str2);
  } else {
    // there is no matching characters in the 2 strings: 
    return false;
  }
}

int main() {
  string str1 = "abcdef";
  string str2 = "?*";
  int n = str1.length();
  int m = str2.length();
}