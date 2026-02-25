#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main () {
  string str1, str2;
  cin>>str1;
  cin>>str2;
  int n = str1.length();
  int m = str2.length();

  if (m == 0) {
    cout<<n;
    return 0;
  }

  vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
  // for (int i = 0; i < n; i++) {
  //   if (str1[0] == str2[i]) {
  //     dp[i][0] = 1;
  //   }
  // }

  // for (int j = 0; j < m; j++) {
  //   if (str1[j] == str2[0]) {
  //     dp[0][j] = 1;
  //   }
  // }

 for (int i = 0; i <=n; i++) {
  for (int j = 0; j <= m; j++) {
    if (i == 0) dp[i][j] = i;
    else if (j == 0) dp[i][j] = j;
    else if (str1[i-1] == str2[j-1]) {
      dp[i][j] = dp[i-1][j-1];
    } else {
      dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
    }
  }
 }

  // for (int i = 0;  i<= n; i++) {
  //   for (int j = 0;  j <= m; j++) {
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
    cout<<endl<<dp[n][m];


}