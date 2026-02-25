#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#define ll long long
#define MOD 1000000007
using namespace std;

int main () {
  ll n, m;
  cin>>n>>m;
  vector<ll> nums;
  for (int i = 0; i < n; i++) {
    ll ele;
    cin>>ele;
    nums.push_back(ele);
  }

  vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

  for (int i = 0; i <= m; i++) {
    if (nums[0] == i || nums[0] == 0) {
      dp[1][i] = 1;
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int k = 1; k <= m; k++) {
      
    }
  }


}

