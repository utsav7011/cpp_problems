#include<iostream>
#include<vector>
using namespace std;

class Node {
  public:
  int data;
  Node* next;
  Node(int data, Node* next) {
    this->data = data;
    this->next = next;
  }
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

Node* deleteHead( Node* head) {
  if (head == NULL) {
    return head;
  }
  head = head->next;
  return head;
}

Node* deleteTail (Node* head) {
  if (head == NULL || head->next == nullptr) {
    return nullptr;
  }
  Node* temp = head;
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = nullptr;
  return head;
}

int main() {
  vector<int> nums = {};
}