#include<iostream>
#include<vector>
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

int upper_bound(vector<int> &nums, int left, int right, int target, int ansIndex) {
  if (left > right) return ansIndex;
  int mid = left + (right - left) / 2;
  if (nums[mid] > target) {
    ansIndex = mid;
    return lower_bound(nums, left, mid-1, target, ansIndex);
  } else {
    return lower_bound(nums, mid+1, right, target, ansIndex);
  }
}


int main() {
  vector<int> nums = {3,7,8,10};
  int n = nums.size();
  int target = 4;
  int floorIndex = lower_bound(nums, 0, n-1, target, -1);
  int cielIndex = upper_bound(nums, 0, n-1, target, -1);
  cout<<endl<<"floor: "<<floorIndex;
  cout<<endl<<nums[floorIndex]<<endl;
  cout<<endl<<"cielIndex: "<<cielIndex;
  cout<<endl<<nums[cielIndex]<<endl;
  if (nums[floorIndex] == target) {
    cout<<endl<<"floor: "<<nums[floorIndex]<<endl;
    cout<<endl<<"ciel: "<<nums[floorIndex]<<endl;
  } else {
    cout<<endl<<"floor: "<<nums[floorIndex-1]<<endl;
    cout<<endl<<"ciel: "<<nums[cielIndex]<<endl;
  }
  return 0;
}