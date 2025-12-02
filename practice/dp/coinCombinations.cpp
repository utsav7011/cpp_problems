#include<vector>
#include<set>
#include<map>
#include<iostream>
#define ll long long
#define mod 1000000007
using namespace std;

ll solve(int N, int X, vector<ll> nums) {
  vector<ll> dp(X+1);
  dp[0] = 1;
  for (int i = 0; i <= X; i++) {
    for (int j = 0; j < N; j++) {
      if (nums[j] > i) {
        continue;
      }
      dp[i] = (dp[i] + dp[i - nums[j]]) % mod;
    }
  }
  return dp[X];
}

int main () {
  ll X;
  ll N;
  cin>>N;
  cin>>X;
  vector<ll> nums;
  for (int i = 0; i < N; i++) {
    int ele;
    cin>>ele;
    nums.push_back(ele);
  }
  cout<<solve(N, X, nums);
}