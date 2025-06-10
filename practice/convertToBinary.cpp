#include<iostream>
using namespace std;

int main() {
  int n = 8;
  string binary = "";
  if (n == 0) binary = "0";
  else {
    while (n > 0) {
      int rem = n % 2;
      if (rem == 1) binary += '1';
      else binary += '0';
      n = n / 2;
    }
    reverse(binary.begin(), binary.end());
  }
  cout<<endl<<binary;
  cout<<endl<<5;
  cout<<endl<<~(-5);
}