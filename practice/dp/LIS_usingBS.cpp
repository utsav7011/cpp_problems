#include<iostream>
#include<vector>
#include<algorithm> // for lower_bound
using namespace std;

int getSmallerIndex (vector<int> &nums, int ele) {
  auto pos = lower_bound(nums.begin(), nums.end(), ele); 
  return (pos - nums.begin());
}

int helper(vector<int> &nums) {
  vector<int> temp;
  for (auto it: nums) {
    if (temp.size() == 0) {
      temp.push_back(it);
    } else if (temp[temp.size()-1] < it) {
      temp.push_back(it);
    } else {
      int index = getSmallerIndex(temp, it);
      nums[index] = it;
    }
  }
  for (auto it: temp) {
    cout<<endl<<it;
  }
  int len = temp.size();
  return len;
}

int main() {
  vector<int> nums = {1,7,334,3,2,8,0,600};
  int n = nums.size();
  cout<<endl<<helper(nums);

}