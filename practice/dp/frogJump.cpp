#include <vector>
#include <iostream>
using namespace std;

int frogJump(int index, int k, vector<int> energies, vector<int> &dp)
{
  if (index < 0) return 0;

  if (index == 0)
    return 0;

  if (dp[index] != -1)
    return dp[index];
  
    int minSteps = INT_MAX;

  for (int j = 1; j <= k; j++) {
    if (index >= j) {
      int res = frogJump(index - j, k, energies, dp) + abs(energies[index] - energies[index - j]);
      minSteps = min(minSteps, res);
    }
  }
  // int left = frogJump(index - 1, energies, dp) + abs(energies[index] - energies[index - 1]) ;
  // int right = INT_MAX;
  // if (index > 1)
  // {
  //   right = frogJump(index - 2, energies, dp) + abs(energies[index] - energies[index - 2]);
  // }

  return dp[index] = minSteps;
}

int main()
{
  int n = 5;
  vector<int> energy = {10, 20, 10, 10, 20};
  vector<int> dp(n , -1);
  int k = 3;
  cout << frogJump(n-1, k, energy, dp);
  // dp[0] = 0;
  // for (int i = 1; i < n; i++) {
  //   int left = abs(energy[i] - energy[i-1]) + dp[i-1];
  //   int right = INT_MAX;
  //   if (i > 1) {
  //     right = abs(energy[i] - energy[i-2]) + dp[i-2];
  //   }
  //   dp[i] = min(left, right);
  // }
  // cout<<endl<<dp[n-1];
}
