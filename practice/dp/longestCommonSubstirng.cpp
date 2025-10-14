#include<iostream>
#include<vector>
using namespace std;

int helper(int i, int j, int n, int m, string str1, string str2, vector<vector<int>> &dp) {
  for (int i = 0; i < n; i++) dp[i][0] = 0;
  for (int j = 0; j <= m; j++) dp[0][j] = 0;

  int maxLen = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str1[i-1] == str2[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
        maxLen = max(maxLen, dp[i][j]);
      } else dp[i][j] = 0;
    }
  }
  return maxLen;
}

int main() {
  string str1 = "abcde";
  string str2 = "abc";
  int n = str1.length();
  int m = str2.length();

  vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
  cout<<endl<<helper(n-1, m-1, n, m, str1, str2, dp);
}