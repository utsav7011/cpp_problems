#include <iostream>
#include <vector>
using namespace std;

bool checkSum(vector<int> &nums, int targetSum)
{
  int sum = 0;
  for (auto it : nums)
  {
    sum += it;
  }
  cout << endl;
  return sum == targetSum;
}

void helper(int index, int n, int targetSum, int &count, int &temp, vector<int> &nums)
{
  if (index == n) {
    if (temp == targetSum) {
      count++;
    }
    return;
  }

  // push ele
  temp += nums[index];
  helper(index + 1, n, targetSum, count, temp, nums);
  temp -= nums[index];
  // do not push ele
  helper(index + 1, n, targetSum, count, temp, nums);
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10};
  int index = 0;
  int n = arr.size();
  int targetSum = 10;
  int temp = 0;
  int count = 0;
  helper(index, n, targetSum, count, temp, arr);
  cout << endl
       << count;
}