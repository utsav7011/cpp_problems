#include <iostream>
using namespace std;

class ListNode
{
  public:
  int val;
  ListNode *next;
  ListNode(int val)
  {
    this->val = val;
    this->next = nullptr;
  }
  ListNode(int val, ListNode *next)
  {
    this->val = val;
    this->next = next;
  }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
      int digit1 = (l1 != nullptr) ? l1->val : 0;
      int digit2 = (l2 != nullptr) ? l2->val : 0;
      int sum = digit1 + digit2 + carry;
      int digit = sum % 10;
      carry = sum / 10;
      ListNode *newNode = new ListNode(digit);
      tail->next = newNode;
      tail = tail->next;
      l1 = (l1 != nullptr) ? l1->next : nullptr;
      l2 = (l2 != nullptr) ? l2->next : nullptr;
    }
    ListNode *ans = dummyHead->next;
    delete dummyHead;
    return ans;
  }
};
int main()
{
}