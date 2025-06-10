#include<iostream>
using namespace std;

int main() {
  int n = 13;
  int i = 2;
  int rightShift = n >> i;
  if (n && rightShift) cout<<"set";
  else cout<<"not set";
}