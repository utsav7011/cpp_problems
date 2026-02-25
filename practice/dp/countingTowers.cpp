#include<iostream>
#include<vector>
#include<map>
#include<set>
// define an alias for long long
using namespace std;
int MOD = 1000000007;

/****
 * 
 * n = 3
 * 3
 * 2
 * 1337
 * 
 * 
 */
vector<vector<int>> dp(1e6+1, vector<int> (2));
int main () {
  long long t;
  cin>>t;
  map<int, int> mem;
  while (t--) {
    long long n;
    cin>>n;
    if (mem.find(n) != mem.end()){
      cout<<endl<<mem[n];
    } else {
      int prevRowHorizontal = 1, currRowHorizontal = 0;
      int prevRowVerticval = 1, currRowVertical = 0;

      for (long long i = n-2; i >= 0; i--) {
        currRowHorizontal = ((2LL * prevRowHorizontal) + prevRowVerticval) % MOD;
        currRowVertical = ((4LL * prevRowVerticval) + prevRowHorizontal) % MOD;
        
        prevRowHorizontal = currRowHorizontal;
        prevRowVerticval = currRowVertical;
      }
      cout<<endl<<(prevRowHorizontal + prevRowVerticval) % MOD;
      mem[n] = (prevRowHorizontal + prevRowVerticval) % MOD;
    }

  }
}