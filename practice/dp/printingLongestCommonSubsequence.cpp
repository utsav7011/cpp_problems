#include<iostream>
#include<vector>
using namespace std;

void helper(int i, int j, int n, int m, string str1, string str2, vector<vector<int>> &dp) {
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }

  for (int j = 0; j <= m; j++) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <=n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str1[i-1] == str2[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
}

int main() {
  string str1 = "abcde";
  string str2 = "acde";
  int n = str1.length();
  int m = str2.length();

  int i = n-1;
  int j = m-1;

  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  helper(i, j, n, m, str1, str2, dp);

  string ans = "";
  
  while (n > 0 && m > 0) {
    if (str1[n-1] == str2[m-1]) {
      ans += str1[n-1];
      n-=1;
      m-=1;
    } else{
      if (dp[n-1][m] > dp[n][m-1]) n-=1;
      else {
        m-=1;
      }
    }
  }

  reverse(ans.begin(), ans.end());
  cout<<endl<<ans;
}