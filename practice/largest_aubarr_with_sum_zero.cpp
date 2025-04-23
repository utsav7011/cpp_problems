// Problem: 1399. Count Largest Group

#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int sum=0;
        int leng=0;
        unordered_map<int, int>m;
        for(int i=0; i<arr.size(); i++)
        {
            sum=sum+arr[i];
            if(sum==0)
            leng=i+1;
            if(m.find(sum)!=m.end())
            {
                leng=max(leng, i-m[sum]);
            }
            else
            m[sum]=i;
        }
        return leng;
    }
};