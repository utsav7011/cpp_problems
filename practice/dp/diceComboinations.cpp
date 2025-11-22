#include<vector>
#include<iostream>
typedef long long ll;
using namespace std;
/**
 * 
 * 0 1 2 4 5 6 7 8 9 10
 * 0 1 
 * 
 */


ll MOD = 1e9+7;

int main () {
  ll target = 0;
  cin>>target;
  vector<long long> dp (target + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= target; i++) {
    for (int j = 1; j <= 6 && j <= i; j++) {
      dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
  }
  cout<<endl<<dp[target];
}