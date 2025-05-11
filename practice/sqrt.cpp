#include<iostream>
using namespace std;

int mySqrt(int x) {
  int low = 0;
  int high = x;
  int mid = 0;
  while (low <= high) {
      mid = (low + high) / 2;
      cout<<endl<<"low" <<low<<" high"<<high<<" mid"<<mid<<endl;
      int val = mid * mid;
      if (val <= x) low = mid+1;
      else high = mid-1; 
  }
  return high;
}

int main() {
  int n = 16;
  cout<<endl<<mySqrt(n);
}