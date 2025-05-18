#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
  Node(int data, Node *next, Node *prev)
  {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }
};

void printDLL(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << endl
         << temp->data;
    temp = temp->next;
  }
  cout << endl;
}

Node *insertNewNodeInMiddle(Node *head, int ele, int eleToInsertAfter)
{
  if (head == nullptr)
  {
    head = new Node(ele);
    return head;
  }
  if (head->next == nullptr && head->data == eleToInsertAfter)
  {
    Node *temp = new Node(ele);
    temp->prev = head;
    head->next = temp;
    return head;
  }
  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == eleToInsertAfter)
    {
      Node *newNode = new Node(ele);
      newNode->next = temp->next;
      newNode->prev = temp;
      temp->next!= nullptr ? temp->next->prev = newNode : newNode->next = NULL;
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }
  return head;
}

Node *insertANewNodeInBeginning(Node *head, int ele)
{
  if (head == nullptr)
  {
    head = new Node(ele);
    return head;
  }
  Node *newNode = new Node(ele);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  return head;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  int i = 0;
  int n = nums.size();
  Node *head = nullptr;
  Node *temp = head;

  while (i < n)
  {
    if (head == NULL)
    {
      head = new Node(nums[i]);
      temp = head;
      i++;
      continue;
    }
    Node *newNode = new Node(nums[i]);
    temp->next = newNode;
    newNode->prev = temp;
    temp = temp->next;
    i++;
  }
  printDLL(head);
  head = insertANewNodeInBeginning(head, 100);
  printDLL(head);
  head = insertNewNodeInMiddle(head, 1000, 4);
  printDLL(head);
}