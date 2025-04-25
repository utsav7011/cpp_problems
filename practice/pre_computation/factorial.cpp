#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int M = 1e9+7;
const int N = 1e5 + 10;
long long fact[N];

int main() {
  // pre_conputation:

  fact[0] = fact[1] = 1;
  for (int i = 2; i < N; i++) {
    fact[i] = fact[i-1] * i;
  }

  int t;
  cin>>t;
  while (t--) {
    int test_case;
    cin>>test_case;
    cout<<fact[test_case]<<endl;
  }

}