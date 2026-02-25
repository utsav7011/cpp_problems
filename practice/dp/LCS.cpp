#include<vector>
#include<set>
#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> nums1, nums2;

  for (ll i = 0; i < n; i++)
  {
    ll ele;
    cin >> ele;
    nums1.push_back(ele);
  }
  for (ll i = 0; i < m; i++)
  {
    ll ele;
    cin >> ele;
    nums2.push_back(ele);
  }

  if (m == 1 && n == 1) {
    if (nums1[0] == nums2[0]) {
      cout<<1<<endl<<nums1[0];
      return 0;
    }
    else {
      cout<<0;
      return 0;
    }
  }

  if (n == 1 && m != 1) {
    for (auto it: nums2) {
      if (it == nums1[0]) {
        cout<<1<<endl<<nums1[0];
        return 0;
      }
    }
    cout<<0<<endl;
    return 0;
  }

  if (m == 1 && n != 1) {
    for (auto it: nums1) {
      if (it == nums2[0]) {
        cout<<1<<endl<<nums2[0];
        return 0;
      }
    }
    cout<<0<<endl;
    return 0;
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

  for (ll i = 1; i <= n; i++)
  {
    for (ll j = 1; j <= m; j++)
    {
      if (nums1[i - 1] == nums2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  
  vector<ll> ans;
  ll i = n;
  ll j = m;
  while (i > 0 && j > 0)
  {
    if (nums1[i - 1] == nums2[j - 1])
    {
      ans.push_back(nums1[i - 1]);
      i = i - 1;
      j = j - 1;
    }
    else
    {
      if (dp[i - 1][j] > dp[i][j - 1])
      {
        i = i - 1;
      }
      else
      {
        j = j - 1;
      }
    }
  }
  
  cout << dp[n][m] << endl;
  reverse(ans.begin(), ans.end());
  for (auto it : ans)
  {
    cout << it << " ";
  }
}