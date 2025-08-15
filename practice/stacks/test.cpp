#include<iostream>
#include<stack>
using namespace std;
// nge

// int main() {
//   stack<int> st;
//   vector<int> nums = {4, 12, 5, 3, 1,2,5,3,1,2,4,6};
//   vector<int> nge(nums.size(), -1);
//   int n = nums.size();
  
//   nge[n-1] = -1;
//   st.push(nums[n-1]);

//   for (int i = n-2; i >= 0; i--) {
//     while (!st.empty() && st.top() <= nums[i]) st.pop();
//     if (st.empty()) {
//       nge[i] = -1;
//       st.push(nums[i]);
//     } else {
//       nge[i] = st.top();
//       st.push(nums[i]);
//     }
//   }
//   for (auto it: nge) cout<<it<<" ";
// }


// nse

// int main() {
//     vector<int> nums = {4, 12, 5, 3, 1,2,5,3,1,2,4,6};
//     stack<int> st;
//     int n = nums.size();
//     vector<int> nse(n, -1);
//     st.push(nums[nums.size()-1]);
//     nse[nums.size()-1] = -1;
//     for (int i = nums.size()-2; i >= 0; i--) {
//       while (!st.empty() && st.top() > nums[i]) st.pop();
//       if (st.empty()) {
//         nse[i] = -1;
//         st.push(nums[i]);
//       } else {
//         nse[i] = st.top();
//         st.push(nums[i]);
//       }
//     }
//     for (auto it: nse) cout<<it<<" ";
// }


