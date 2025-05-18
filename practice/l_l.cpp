#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
  }
};

Node *insertNodeInLLInBegining(Node *head, int ele)
{
  Node *newNode = new Node(ele);
  Node *temp = head;
  newNode->next = head;
  head = newNode;
  return head;
}

Node *insertInBetweenLL(Node *head, int eleToInsertAfter, int ele)
{
  Node *newNode = new Node(ele);
  Node *temp = head;
  while (temp != nullptr)
  {
    if (temp->data == eleToInsertAfter)
    {
      newNode->next = temp->next;
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }
  return head;
}

Node *insertNodeAtLast(Node *head, int ele)
{
  if (head == NULL)
    return head;
  if (head->next == nullptr)
  {
    head->next = new Node(ele);
    return head;
  }
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new Node(ele);
  return head;
}

Node *deleteFirstNode(Node *head)
{
  if (head == nullptr)
    return head;
  return head->next;
}

Node *deleteNodeFromMiddle(Node *head, int ele)
{
  if (head == NULL)
    return head;
  if (head->data == ele) {
    return head->next;
  }
  Node *temp = head;
  while (temp->next != NULL)
  {
    if (temp->next->data == ele) {
      temp->next = temp->next->next;
      free(temp->next);
    }
  }
  return head;
}

void printLL(Node *head)
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

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  Node *head = nullptr;
  int i = 0;
  int n = nums.size();
  Node *temp = head;
  while (i < n)
  {
    if (head == nullptr)
    {
      head = new Node(nums[i]);
      temp = head;
    }
    else
    {
      temp->next = new Node(nums[i]);
      temp = temp->next;
    }
    i++;
  }
  printLL(head);
  head = insertNodeInLLInBegining(head, 2);
  printLL(head);

  head = insertInBetweenLL(head, 3, 50);
  printLL(head);

  head = deleteNodeFromMiddle(head, 2);
  cout<<endl<<endl;
  printLL(head);
}