#include<iostream>
#include<vector>
using namespace std;

int helper(int index, int n, int target, vector<int> &coins) {
  if (index == 0) {
    if (target % coins[index] == 0) return target / coins[index];
    else return 0;
  }

  if (target == 0) return 1;

  int notTake = helper(index-1, n, target, coins);
  int take = INT_MAX;
  if (target >= coins[index]) {
    take = 1 + helper(index, n, target - coins[index], coins);
  }

  return min(take, notTake);
}

int main() {
  vector<int> coins = {1,2,5};
  int n = coins.size();
  int index = n-1;
  int target = 11;
  int ans = helper(index, n, target, coins);
  cout<<endl<<ans;

  vector<vector<int>> dp(n, vector<int> (target+1, -1));

  for (int i = 0;  i< n; i++) {
    dp[i][0] = 0;
  }

  for (int j = 1; j <= target; j++) {
    if (j % coins[0] == 0 ) dp[0][j] = j / coins[0]; 
  }


  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= target; j++) {
      int notTake = dp[i-1][j];
      int take = INT_MAX;
      if (j >= coins[i]) {
        take = 1 + dp[i][target - coins[i]];
      }
    }
  }


}