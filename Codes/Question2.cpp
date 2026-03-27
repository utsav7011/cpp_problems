#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main () {
  vector<int> vec = {1,2,4, 6, 10};
  int i = 0;
  int j = vec.size()-1;
  int target = 15;
  bool flag = false;
  while (i < j) {
    if (target - vec[i] == vec[j]) {
      flag = true; 
      break;
    }
    if (target - vec[i] > vec[j]) i++;
    if (target - vec[i] < vec[j]) j--;
  }
  if (flag) cout<<endl<<"pair exists";
  else cout<<endl<<"Pair does not exists";
}
