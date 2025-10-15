#include <iostream>
#include <vector>
using namespace std;

/*

  babaababd
  i = 0;
  j = 4



)*/

int helper(int i, int j, int n, string str1, string str2, vector<vector<int>> &dp)
{
  if (i < 0 || j < 0)
    return 0;
  if (dp[i][j] != -1) return dp[i][j];
  if (str1[i] == str2[j])
  {
    return dp[i][j] = 1 + helper(i - 1, j - 1, n, str1, str2, dp);
  }
  else
  {
    return dp[i][j] = 0 + max(helper(i - 1, j, n, str1, str2, dp), helper(i, j - 1, n, str1, str2, dp));
  }
}

int main()
{
  string str1 = "abcdedcba";
  int n = str1.length();
  int i = n - 1;
  int j = n - 1;
  string str2 = str1;

  reverse(str2.begin(), str2.end());
  vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
  cout << endl
       << helper(i, j, n, str1, str2, dp);
}