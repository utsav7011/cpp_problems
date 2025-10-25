// stocks:

#include<iostream>
using namespace std;

int main() {
  vector<int> stockPrices = {7,1,5,3,6,2};
  int n = stockPrices.size();
  int profit = 0;
  int mini = stockPrices[0];
  for (int i = 1; i < n; i++) {
    int cost = stockPrices[i] - mini;
    profit = max(profit, cost);
    mini = min(mini, stockPrices[i]);
  }

  cout<<endl<<profit;
}