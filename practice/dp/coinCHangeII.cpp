#include<iostream>
#include<vector>
using namespace std;

int helper(int index, int n, int target, vector<int> &rods, vector<int> &price) {
  if (index == 0) {
    if (target % rods[index] == 0) return (target / rods[index]) * price[index];
    else return INT_MIN;
  }

  if (target == 0) {
    return 0;
  }
  
  int notTake = 0 + helper(index-1,n, target, rods, price);
  int take = INT_MIN;
  if (target >= rods[index]) {
    take = price[index] + helper(index, n, target - rods[index], rods, price);
  }

  return max(take , notTake);
}

int main() {
  vector<int> rods = {5,4,3,2,1};
  vector<int> price = {10, 20, 15, 5, 1};
  int n = rods.size();
  int index = n-1;
  int target = 20;
  cout<<endl<<helper(index, n, target, rods, price);
}