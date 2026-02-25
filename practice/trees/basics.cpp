#include<iostream>
using namespace std;

class Node {
  public:
  int val;
  Node* left;
  Node* right;
  Node(int val) {
    this->left = nullptr;
    this->right = nullptr;
    this->val = val;
  }
};


// DFS serarch: 
// inorder traversal
void inOrderTraversal(Node* node) {
  if (node == nullptr) return;
  inOrderTraversal(node->left);
  cout<<endl<<node->val;
  inOrderTraversal(node->right);
}
// postoeder traversal

// preorder traverasl

int main () {
  Node* root = new Node(10);

}