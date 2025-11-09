#include<iostream>
using namespace std;

bool isPalindrome(string str) {
  int i  = 0;
  int j = str.length();
  while (i < j) {
    if (str[i] == str[j]) {
      i++; 
      j--;
    } else {
      return false;
    }
  }
  return true;
}

int helper(int i, int n, string str) {
  if (i == n) return 0;
  string temp = "";
  int minCuts = INT_MAX;
  for (int k = i; k < n; k++) {
    temp += str[k];
    int tempCuts = 0;
    if (isPalindrome(temp)) {
      tempCuts = 1 + helper(i+1, n, str);
    }
    minCuts = min(minCuts, tempCuts);
  }
}

int main () {
  string str = "babacbadcede";
  int len = str.size();
  int index = 0;
}