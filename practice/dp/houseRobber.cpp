#include<iostream>
#include<vector>
using namespace std;

int knapSack(vector<int> &nums, int n) {
  if (n < 0) return 0;
  if (n == 0) return nums[0];

  int pick = INT_MIN;
  if (n > 1) {
    pick = nums[n] + knapSack(nums, n-2);
  }
  int notPick = knapSack(nums, n-1);
  return max(pick ,notPick);
}

int main() {
  int n = 5;
  vector<int> houseMoney = {10, 20, 50, 100, 20};

}