#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n];
  unordered_map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mpp[a[i]]++;
  }
  int q;
  cin >> q;

  while (q--)
  {
    int x;
    cin >> x;
    cout << mpp[x] << endl;
  }
}