#include <iostream>
#include<vector>
using namespace std;

class Node
{
  public:
  int data;
  Node *next;
  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
  }
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

Node* convertArrToLL (vector<int> nums) {
  Node* head = new Node(nums[0]);
  Node* mover = head;
  int i = 1;
  int n = nums.size();
  while (i < n) {
    Node* newNode = new Node(nums[i]);
    mover->next = newNode;
    mover = mover-> next;
    i++;
  }
  cout<<endl<<"Linked List Created: "<<endl;
  return head;
}

int lengthOfLL(Node* head) {
  int length = 0;
  while (head!= NULL) {
    length+=1;
    head = head->next;
  }
  return length;
}

Node* deleteNode(Node* head, int ele) {
  Node* prev = head;
  Node* temp = head->next;
  while (temp!= NULL){
    
    if (temp->data == ele) {
      prev->next = temp->next;
      break;
    }
    prev = prev->next;
    temp = temp->next;
  }
  cout<<endl<<"Node deleted"<<endl;
  return head;
}

int main()
{
  vector<int> nums = {1,2,3,4};
  Node* head = convertArrToLL(nums);
  Node*temp = head;
  while (temp!= NULL) {
    cout<<endl<<temp->data;
    temp = temp->next;
  }
  int length = lengthOfLL(head);
  cout<<endl<<"Length of Linked List: "<<length<<endl;

  int ele = 2;
  Node* resultHead = deleteNode(head, ele);
  while (resultHead!= NULL) {
    cout<<endl<<resultHead->data;
    resultHead = resultHead->next;
  }
}