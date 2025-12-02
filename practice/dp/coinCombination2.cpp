#include <vector>
#include <map>
#include <set>
#include <iostream>
#define ll long long
#define MOD 1000000007
using namespace std;

ll helper(ll index, ll n, ll target, vector<ll> &nums, vector<vector<ll>> &dp)
{
  if (target == 0)
    return 1;
  if (index == 0)
  {
    return (target % nums[index] == 0) ? 1 : 0;
  }
  if (dp[index][target] != -1)
    return dp[index][target];
  ll notTake = helper(index - 1, n, target, nums, dp);
  ll take = 0;
  if (nums[index] <= target)
  {
    take = helper(index, n, target - nums[index], nums, dp);
  }
  return dp[index][target] = take + notTake;
}

int main()
{
  ll n, x;
  cin >> n;
  cin >> x;
  vector<ll> nums;
  for (ll i = 0; i < n; i++)
  {
    ll ele;
    cin >> ele;
    nums.push_back(ele);
  }
  // vector<vector<ll>> dp(n, vector<ll>(x + 1, -1));
  // cout << endl
  //      << helper(n - 1, n, x, nums, dp) << endl;


  // vector<vector<ll>> dp(n, vector<ll> (x+1, 0));

  // for (ll i = 0; i < n; i++) {
  //   dp[i][0] = 1;
  // }

  // for (ll j = 0; j <= x; j++) {
  //   if (j >= nums[0] && j % nums[0] == 0) {
  //       dp[0][j] = 1;
  //   }
  // }

  // for (ll i = 1; i < n; i++) {
  //   for (ll j = nums[i]; j <= x; j++) {
  //     ll notTake = dp[i-1][j];
  //     ll take = 0;
  //     if (nums[i] <= j) {
  //       take = dp[i][j - nums[i]];
  //     }
  //     dp[i][j] = (take + notTake) % MOD;
  //   }
  // }

  // cout<<endl<<dp[n-1][x];

  vector<int> dp(x+1, 0);
  dp[0] = 1;
  for (int i =0; i < n; i++) {
    for (int j = nums[i]; j <=x; j++) {
      dp[j] = (dp[j] + dp[j - nums[i]]) % MOD;
    }
  }

  cout<<endl<<dp[x];
}
