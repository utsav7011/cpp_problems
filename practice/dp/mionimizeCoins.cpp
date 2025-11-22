#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

const ll MOD = 1e18;

int main () {
  ll n, x;
  cin>>n;
  cin>>x;
  vector<ll> coins;
  vector<ll> dp(x+1, MOD);
  for (ll i = 0; i < n; i++) {
    int ele;
    cin>>ele;
    coins.push_back(ele);
  }
  for (int target = 1; target <=x; target++) {
    for (int j = 0; j < n; j++) {
      if (coins[j] > target || dp[target - coins[j]]== MOD) {
        continue;
      } else {
        dp[target] = min(dp[target], 1 + dp[target - coins[j]]);
      }
    }
  }

  if (dp[x] == MOD) {
    cout<<endl<<dp[x];
  } else {
    cout<<endl<<-1;
  }
}
