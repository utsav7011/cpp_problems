#include<iostream>
using namespace std;

void push (queue<int> &q, int ele) {
  if (q.empty()) {
    q.push(ele);
  }
  else {
    q.push(ele);
    while (q.front()!= ele) {
      int temp = q.front();
      q.pop();
      q.push(temp);
    }
  }
  return;
}

int main() {

}