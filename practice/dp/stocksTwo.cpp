#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int helper(int index, int n, bool sell, vector<int> &prices, vector<vector<int>> &dp) {
        if (index == n) return 0;
        if (dp[index][sell] != -1) return dp[index][sell];
        if (sell) {
            return dp[index][sell] = max(prices[index] + helper(index+1, n, false, prices, dp), 0 + helper(index+1, n, true, prices, dp));
        }
        else {
            return dp[index][sell] = max(helper(index+1, n, true, prices, dp) - prices[index], helper(index+1, n, false, prices, dp) - 0);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int index = 0;
        bool sell = false;
        // vector<vector<int>> dp(n+1, vector<int> (2, -1));
        // return helper(index, n, sell, prices, dp);

        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                if (j) {
                    // if sell is true: 
                    dp[i][j] = max(dp[i+1][0] + prices[i], dp[i+1][1] + 0);
                } else {
                    // is sell is false
                    dp[i][j] = max(dp[i+1][1] - prices[i], dp[i+1][0]);
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
  vector<int> prices = {7,1,5,3,6,4};
  int n = prices.size();

}