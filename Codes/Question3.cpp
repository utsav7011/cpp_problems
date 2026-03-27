#include <iostream>
#include <vector>
using namespace std;

int findNextVowelFromStart(string str, int prevIndex)
{
  while (prevIndex < str.length() && !(str[prevIndex] == 'a' || str[prevIndex] == 'u' || str[prevIndex] == 'o' || str[prevIndex] == 'i' || str[prevIndex] == 'e'))
  {
    prevIndex++;
  }
  return prevIndex;
}
int findNextWowelFromEnd(string str, int prevIndex)
{
  while (prevIndex >= 0 && !(str[prevIndex] == 'a' || str[prevIndex] == 'u' || str[prevIndex] == 'o' || str[prevIndex] == 'i' || str[prevIndex] == 'e'))
  {
    prevIndex--;
  }
  return prevIndex;
}


void removeDuplicteArray(vector<int> vec) {
  int i = 0;
  int j = i+1;
  int n = vec.size();
  while (j < n) {
    if (vec[i] == vec[j]) {
      while (vec[i] == vec[j] && j < n) j++;;
      vec.erase(vec.begin() + i+1, vec.begin()+j-1);
      i = j;
      j+=1;
    } else {
      i++;
      j++;
    }
  }
  
  for (auto it: vec) cout<<it<<" ";
}

int main()
{
  string str = "eo";
  int n = str.length();
  int i = findNextVowelFromStart(str, 0);
  int j = findNextWowelFromEnd(str, n - 1);

  cout<<endl<<i<<" "<<j;

  while (i < j) {
    swap(str[i], str[j]);
    i = findNextVowelFromStart(str, i+1);
    j = findNextWowelFromEnd(str, j-1);
  }
  cout<<endl<<str;

  vector<int> vec1 = {1, 1,2,2,2,2,2,2,3,3,3,3,3, 4};
  removeDuplicteArray(vec1);
}