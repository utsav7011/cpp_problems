#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
  int minTimeToReach(vector<vector<int>> &moveTime)
  {
    int n = moveTime.size();
    int m = moveTime[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
        minh;
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    minh.push({0, 0, 0});
    moveTime[0][0] = 0;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while (!minh.empty())
    {
      auto current = minh.top();
      minh.pop();
      int currentTime = current[0];
      int currentRow = current[1];
      int currentCol = current[2];
      if (currentTime >= dp[currentRow][currentCol])
        continue;
      if (currentRow == n - 1 && currentCol == m - 1)
        return currentTime;
      dp[currentRow][currentCol] = currentTime;
      for (auto &direction : directions)
      {
        int nextRow = currentRow + direction[0];
        int nextCol = currentCol + direction[1];
        if (nextRow >= 0 && nextRow < n && nextCol >= 0 &&
            nextCol < m && dp[nextRow][nextCol] == INT_MAX)
        {
          int cost = (currentCol + currentRow) % 2 + 1;
          int start = max(moveTime[nextRow][nextCol], currentTime);
          int nextTime = start + cost;
          minh.push({nextTime, nextRow, nextCol});
        }
      }
    }
    return -1;
  }
};