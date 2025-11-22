#include<vector>
#include<set>
#include<map>
#include<iostream>
#define ll long long
using namespace std;

ll MOD = 1e9+7;

ll helper(ll index, ll target, vector<ll> &nums, vector<vector<ll>> &dp) {

  if (target == 0) return 1;
  if (index == 0) {
    if (target % nums[index] == 0) {
      return 1;
    }
    return 0;
  }

  if (dp[index][target] != -1) return dp[index][target];
  ll notTake = helper(index-1, target, nums, dp);
  ll take = 0;
  if (nums[index] <= target) {
    take = 1 + helper(index, target - nums[index], nums, dp);
  }

  return dp[index][target] = (take + notTake) % MOD;
}

int main () {
  ll n, x;
  cin>>n;
  cin>>x;
  vector<ll> nums(n);
  // input of the elements:
  for (ll i = 0; i < n; i++) {
    ll ele;
    cin>>ele;
    nums[i] = ele;
  }

  sort(nums.begin(), nums.end());
  vector<vector<ll>> dp(n+1, vector<ll> (x+1, -1));
  ll ans = helper(n-1, x, nums, dp);
  cout<<endl<<ans;
}