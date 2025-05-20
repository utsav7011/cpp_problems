#include<iostream>
#include<vector>
using namespace std;

class Node {
  public:
  int data;
  Node* next;
  Node(int d) {
    this->data = d;
    this->next = NULL;
  }
  Node(int d, Node* n) {
    this->data = d;
    this->next = n;
  }
};

Node* detectLengthOfLoop(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while (fast != NULL && fast-> next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      while (fast!= slow) {
        fast = fast->next;
        slow = slow->next;
      }
      return slow;
    }
  }
  return NULL;
}

int main(){
  Node* head = NULL;
}