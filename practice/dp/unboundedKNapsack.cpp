#include <iostream>
#include <vector>
using namespace std;

int helper(int index, int n, int target, vector<int> &price, vector<int> &weight, vector<vector<int>> &dp)
{
  if (target == 0)
  {
    return 0;
  }
  if (index == 0)
  {
    if ((weight[index] <= target) && (target % weight[index]) == 0)
    {
      return (target / weight[index]) * price[index];
    }
    else
      return 0;
  }
  if (dp[index][target] != -1) return dp[index][target];
  int notTake = helper(index - 1, n, target, price, weight, dp);
  int take = INT_MIN;
  if (target >= weight[index])
  {
    take = price[index] + helper(index, n, target - weight[index], price, weight, dp);
  }
  return dp[index][target] = max(take, notTake);
}

int main()
{
  vector<int> prices = {10, 20, 5};
  vector<int> weights = {1, 4, 2};
  int n = prices.size();
  int index = n - 1;
  int target = 20;
  vector<vector<int>> dp(n, vector<int> (target+1, -1));
  int ans = helper(index, n, target, prices, weights, dp);
  cout << endl
       << ans;
}