#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<set>
#include<climits>
#define ll long long
using namespace std;

/***
 * 
 * 4 10
 * 4 8 5 3
 * 5 12 8 1
 * 
 */


// ll helper(ll index, ll n, ll x, vector<ll> pages, vector<ll> prices, vector<vector<ll>> &dp) {
//   if (x < 0 || index < 0) return 0;
//   if (index == 0) {
//     if (x >= pages[0]) return pages[0];
//     else return 0;
//   }

//   if (dp[index][x] != -1) return dp[index][x];

//   ll notPickBook = 0 + helper(index-1, n, x, pages, prices, dp);
//   ll pickBook = INT_MIN;
//   if (prices[index] <= x) {
//     pickBook = pages[index] +  helper(index-1, n, x - prices[index], pages, prices, dp);
//   }

//   return dp[index][x] = max(pickBook, notPickBook);
// }


ll helper(ll index, ll x, vector<ll> pages, vector<ll> prices, vector<vector<ll>> &dp) {
  if (x < 0 || index < 0) return 0;
  if (index == 0) {
    if (prices[index] <= x) return pages[index];
    else return 0;
  }

  if (dp[index][x] != -1) return dp[index][x];
  
  ll notPick = helper(index-1, x, pages, prices, dp);
  ll pick = INT_MIN;
  if (prices[index] <= x) {
    pick = pages[index] + helper(index-1, x - prices[index], pages, prices, dp);
  }

  return dp[index][x] = max(pick, notPick);
}

int main () {
  ll n, x;
  cin>>n>>x;
  vector<ll> prices;
  vector<ll> pages;

  for (ll i = 0; i < n; i++) {
    ll price;
    cin>>price;
    prices.push_back(price);
  }
  for (ll i = 0; i< n; i++) {
    ll page;
    cin>>page;
    pages.push_back(page);
  }
  // vector<vector<ll>> dp(n+1, vector<ll> (x+1, -1));
  // cout<<endl<<helper(n-1, x, pages, prices, dp);


  vector<ll> prev(x+1, 0);
  vector<ll> curr(x+1, 0);

  for (int j = 0; j <= x; j++) { 
    if (prices[0] <= j) prev[j] = pages[0];
  }

  for (ll i = 1; i < n; i++) {
    for (ll j = 1; j <=x; j++) {
      ll notPick = prev[j];
      ll pick = INT_MIN;
      if (prices[i] <= j ) {
        pick = pages[i] + prev[j - prices[i]];
      }
      curr[j] = max(pick, notPick);
    }
    prev = curr;
  }

  cout<<endl<<curr[x];
}