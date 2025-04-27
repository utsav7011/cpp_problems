// Lower bound: ans[mid] >= target
// aim is to find the first occurring element that is equal to or gratter that the target(id the target is not present in the array)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lower_bound(vector<int> &nums, int left, int right, int target, int ansIndex) {
  if (left > right) return ansIndex;
  int mid = left + (right - left) / 2;
  if (nums[mid] >= target) {
    ansIndex = mid;
    return lower_bound(nums, left, mid-1, target, ansIndex);
  } else {
    return lower_bound(nums, mid+1, right, target, ansIndex);
  }
}

int main() {
  vector<int> arr  ={1,2,3,4,5,7,8,9};
  int left = 0;
  int right = arr.size()-1;
  int target = 6;
  int ansIndex = lower_bound(arr, left, right, target, -1);
  cout<<endl<<arr[ansIndex]<<endl;
  return 0;
}
