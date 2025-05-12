#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  vector<int> findEvenNumbers(vector<int> &digits)
  {
    vector<int> ans;
    vector<int> freq(10, 0);
    for (auto it : digits)
      freq[it]++;

    for (int i = 100; i < 1000; i += 2)
    {
      int a = i / 100;
      int b = (i / 10) % 10;
      int c = (i % 10);
      vector<int> local(10, 0);
      local[a]++;
      local[b]++;
      local[c]++;
      bool valid = true;
      for (int j = 0; j < 10; j++)
      {
        if (local[j] > freq[j])
        {
          valid = false;
          break;
        }
      }
      if (valid)
        ans.push_back(i);
    }
    return ans;
  }
};