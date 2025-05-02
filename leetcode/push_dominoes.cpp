#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  string pushDominoes(string dominoes)
  {
    queue<pair<int, char>> q;
    for (int i = 0; i < dominoes.size(); i++)
    {
      if (dominoes[i] != '.')
        q.push({i, dominoes[i]});
    }
    int n = dominoes.length();
    string res = dominoes;
    while (!q.empty())
    {
      auto ind = q.front().first;
      auto dir = q.front().second;
      q.pop();
      if (dir == 'L')
      {
        if (ind - 1 >= 0 && res[ind - 1] == '.')
        {
          res[ind - 1] = 'L';
          q.push({ind - 1, 'L'});
        }
      }
      else if (dir == 'R')
      {
        if (ind + 1 < n && res[ind + 1] == '.')
        {
          if (ind + 2 < n && res[ind + 2] == 'L')
          {
            q.pop();
          }
          else
          {
            res[ind + 1] = 'R';
            q.push({ind + 1, 'R'});
          }
        }
      }
    }
    return res;
  }
};