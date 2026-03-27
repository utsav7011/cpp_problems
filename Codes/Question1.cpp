/****
 * loop once: O(n)
 * twice loop O(n square)
 * half the search space each time: O(logn)
 * 
 * 
 */


#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
  int a = 55;
  vector<int> vec = {1,2,3};

  vec.push_back(100);
  vec.push_back(200);
  for (auto it: vec) {
    cout<<endl<<it;
  }

  int i = 0;
  int n = vec.size();
  while (i < n/2) {
    int temp = vec[i];
    vec[i] = vec[n - 1 - i];
    vec[n - 1 - i] = temp;
    i++;
  }

  for (auto it: vec) cout<<it<<endl;
}