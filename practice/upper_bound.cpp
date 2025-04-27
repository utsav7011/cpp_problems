// Upper bound....
// to find the first occurring element that if greater than index in the given array;
// ans[mid] > target

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int upper_bound(vector<int> &arr, int left, int right, int target, int ansIndex) {
  if (left > right) return ansIndex;
  int mid = left + (right - left) / 2;
  if (arr[mid] > target) {
    ansIndex = mid;
    return upper_bound(arr, left, mid-1, target, ansIndex);
  } else {
    return upper_bound(arr, mid+1, right, target, ansIndex);
  }
}

int main() {
  vector<int> arr = {1,2,3,4,5,6,7,8,9};
  int left = 0;
  int right = arr.size() - 1;
  int target = 1;
  int targetIndex = upper_bound(arr, left, right, target, -1);
  cout << endl << arr[targetIndex] << endl;
  return 0;
}