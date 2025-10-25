#include<iostream>
using namespace std;

int helper(int index, int n, bool sell, vector<int> &prices, vector<vector<int>> &dp) {
  if (index >= n) return 0;
  
  if (dp[index][sell] != -1) return dp[index][sell];

  if (sell) {
    return dp[index][sell] = max(helper(index+2, n, false, prices, dp)+ prices[index], helper(index+1, n, true, prices, dp));
  } else {
    return dp[index][sell]= max(helper(index+1, n, true, prices, dp) - prices[index], helper(index+1, n, false, prices, dp));
  }
}

int main() {
  vector<int> prices = {6,5,1,8,0,1,99};
  int n = prices.size();
  bool sell = false;
  vector<vector<int>> dp(n+1, vector<int> (2, -1));
  cout<<endl<<helper(0, n, sell, prices, dp);

}