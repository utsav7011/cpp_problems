/**
 * Given an array of N integers, given Q queries and in each query, given L and r
 * print the sum of array elements from index L to R (L and R included);
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

const int N = 1e5+10;

int main() {
  int n ;
  cin>>n;
  vector<int> arr;
  unordered_map<int, int> mpp;

  for (int i = 0;  i< n; i++) {
    int ele;
    cin>>ele;
    arr.push_back(ele);
    if (i == 0) {
      mpp[0] = ele;
    } else {
      mpp[i] = mpp[i-1] + ele;
    }
  }
  for (auto it : mpp) {
    cout<<it.first<<" "<<it.second<<endl;
  }
  int q;
  cin>>q;
  while (q--) {
    int l, r;
    cin>>l >> r;
    cout<<endl<<"Sum of : "<<l << " to " << r << " is : "<<mpp[r] - mpp[l-1];
  }
}