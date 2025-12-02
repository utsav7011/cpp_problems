#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#define ll long long
#define MOD 1000000007
using namespace std;
/**
 * 27 -> 20 -> 18 -> 10 -> 9 -> 0
 */

int main () {
  int n ;
  cin>>n;

  vector<ll> dp(n+1, 1e9);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    ll temp = i;
    while (temp) {
      ll d = temp % 10;
      dp[i] = min(dp[i], 1 + dp[i - d]);
      temp /= 10; 
    }
  }
  cout<<endl<<dp[n];
}