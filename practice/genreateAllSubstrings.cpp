#include <iostream>
#include <string>
using namespace std;

void generateAllSubStrings(int n, string temp, vector<string> &ans)
{
  if (temp.length() == n)
  {
    ans.push_back(temp);
    return;
  }

  generateAllSubStrings(n, temp+"0", ans);
  generateAllSubStrings(n, temp+"1", ans);
}

int main()
{
  int n;
  cin >> n;
  vector<string> ans;
  string temp = "";
  generateAllSubStrings(n, temp, ans);
  for (auto it : ans)
  {
    cout << endl
         << it;
  }
}