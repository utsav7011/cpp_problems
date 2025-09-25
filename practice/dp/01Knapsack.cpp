#include<vector>
#include<map>
#include<iostream>
using namespace std;

int knapSack(int index, int n, int wt, vector<int> &wNums, vector<int> prices, vector<vector<int>> &dp) {
  if (index == 0) {
    if (wt >= wNums[index]) {
      return prices[index];
    }
    return INT_MIN;
  }

  if (dp[index][wt] != -1) return dp[index][wt];
  // not pick
  int notPick = 0 + knapSack(index-1, n, wt, wNums, prices, dp);
  // pick
  int pick = INT_MIN;
  if (wt >= wNums[index]) {
    pick = prices[index] + knapSack(index-1, n, wt - wNums[index], wNums,  prices, dp);
  }
  return dp[index][wt] = max(pick, notPick);
}

int main () {
  vector<int> wt = {3,4,5,6,7};
  vector<int> price = {30, 50, 60, 90, 100};
  int n = wt.size();
  vector<vector<int>> dp(n, vector<int> (9, -1));
  cout<<endl<<knapSack(n-1, n, 8, wt, price, dp);
}