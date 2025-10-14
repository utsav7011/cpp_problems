#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helper(int i, int j, string str1, string str2,
             vector<vector<int>> &dp)
  {
    if (i < 0 || j < 0)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    if (str1[i] == str2[j])
    {
      return dp[i][j] = 1 + helper(i - 1, j - 1, str1, str2, dp);
    }
    else
    {
      return dp[i][j] = max(helper(i - 1, j, str1, str2, dp),
                            helper(i, j - 1, str1, str2, dp));
    }
  }
  int longestCommonSubsequence(string text1, string text2)
  {
    int n = text1.length();
    int m = text2.length();
    int i = n - 1;
    int j = m - 1;
    // vector<vector<int>> dp(n, vector<int> (m, -1));
    // return helper(i, j ,text1, text2, dp);

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
    {
      dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
      dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (text1[i - 1] == text2[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[n][m];
  }
};

int main()
{
  string str1 = "abcde";
  string str2 = "acde";

  int n = str1.length();
  int m = str2.length();

  int i = n - 1;
  int m = m - 1;
  Solution s = Solution();
  cout << endl
       << s.longestCommonSubsequence(str1, str2);
}