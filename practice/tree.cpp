#include <iostream>
#include <string>
#include<queue>
using namespace std;

/**
 * 
 * 4 2 6 5 7 1 3
 * 
 */

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }

  Node(int d, Node *left, Node *right)
  {
    data = d;
    this->left = left;
    this->right = right;
  }
};

void inOrderTraversal(Node *root)
{
  // LNR
  if (root == NULL)
    return;
  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
  // NLR
  if (root == NULL)
    return;
  cout << root->data << " ";
  inOrderTraversal(root->left);
  inOrderTraversal(root->right);
}

void iterativePreorder(Node* root) {
  stack<Node*> st;
  st.push(root);
  while (!st.empty()) {
    auto topNode = st.top();
    st.pop();
    cout<<topNode->data<<" ";
    if (topNode->right!= NULL) st.push(topNode->right);
    if (topNode->left!= NULL) st.push(topNode->left);
  }
}

void postOrderraversal(Node *root)
{
  // LRN
  if (root == NULL)
    return;
  inOrderTraversal(root->left);
  inOrderTraversal(root->right);
  cout << root->data << " ";
}

void inOrderIterative(Node* root) {
  stack<Node*> st;
  Node* temp =  root;
  while (true) {
    if (temp != nullptr) {
      st.push(temp);
      temp = temp->left;
    } else {
      if (st.empty()) break;
      temp = st.top();
      st.pop();
      cout<<temp->data<<" ";
      temp = temp->right;
    }
  }
}

void postOrderTraversal(Node* root) {
  
}

void bfs(Node *root) {
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    Node* top = q.front();
    cout<<endl<<top->data;
    q.pop();
    if (top->left != nullptr) q.push(top->left);
    if (top->right != nullptr) q.push(top->right);
  }
}

int main()
{
  Node *root = new Node(10);
  root->left = new Node(100);
  root->right = new Node(20);
  cout << endl
       << root->data;
  cout << endl
       << root->left->data;
  cout << endl
       << root->right->data;
       cout<<endl<<"inOrderTraversal";
  inOrderTraversal(root);
  cout<<endl<<"preOrderTraversal";
  preOrderTraversal(root);
  cout<<endl<<"postOrder";
  postOrderraversal(root);
  cout<<endl<<"bfs";
  bfs(root);
}