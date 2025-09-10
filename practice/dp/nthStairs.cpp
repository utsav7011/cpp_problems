#include<iostream>
#include<vector>
using namespace std;

int nthStair (int n) {
  if (n < 0) return 0;
  if (n == 0) return 1;
  return nthStair(n - 1) + nthStair(n - 2);
}

int main() {
  int n = 3;
  cout<<nthStair(n);
}