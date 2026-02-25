#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

class Node {
  public:
  int val;
  Node* left;
  Node* right;
  Node(int val) {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

void preOrderTraversal (Node* node) {
  if (node == NULL) return;
  cout<<endl<<node->val;
  preOrderTraversal(node->left);
  preOrderTraversal(node->right);
}


void inOrderTraversal (Node* node) {
  if (node == NULL) return;
  inOrderTraversal(node->left);
  cout<<endl<<node->val;
  inOrderTraversal(node->right);
}

void postOrderTraversal(Node* node) {
  if (node == NULL) return;
  postOrderTraversal(node->left);
  postOrderTraversal(node->right);
  cout<<endl<<node->val;
}



void BFSTraversal(Node* node) {
  queue<Node*> q;
  q.push(node);
  while(!q.empty()) {
    auto top = q.front();
    q.pop();
    cout<<endl<<top->val;
    if (top->left != NULL) {
      q.push(top->left);
    }
    if (top->right != NULL) {
      q.push(top->right);
    }
  } 
}



// level wise traveral of nodes: 
void levelWiseTraversal(Node* node) {
  queue<Node*> q;
  q.push(node);
  vector<vector<int>> ans;
  while (!q.empty()) {
    vector<int> levelNodes;
    int n =q.size();
    for (int i = 0;  i < n; i++) {
      auto top = q.front();
      q.pop();
      if (top -> left != NULL) {
        q.push(top->left);
      }
      if (top->right != NULL) {
        q.push(top->right);
      }
      levelNodes.push_back(top->val);
    }
    ans.push_back(levelNodes);
  } 


  for (auto temp: ans) {
    for (auto nodes: temp) {
      cout<<endl<<nodes<<" ";
    }
    cout<<endl;
  }
}


void iterativePreOrderTraversal (Node* node) {
  stack<Node*> st;
  st.push(node);
  while (!st.empty()) {
    auto top = st.top();
    st.pop();
    cout<<endl<<top->val;
    if (top->right != NULL) st.push(top->right);
    if (top->left != NULL) st.push(top->left);
  }
}

void iterativeInOrderTraversal(Node* node) {
  stack<Node*> st;
  Node* current = node;
  
  while (current != NULL || !st.empty()) {
    // Go to leftmost node
    while (current != NULL) {
      st.push(current);
      current = current->left;
    }
    
    // current is NULL, pop from stack
    current = st.top();
    st.pop();
    cout << endl << current->val;  // Print in-order
    
    // Visit right subtree
    current = current->right;
  }
}

int main () {
  Node* head = new Node(10);
  head->left  = new Node(2);
  head->right = new Node(3);
  head->left-> left = new Node(1);
  head->left->right = new Node(5);
  head->right->left = new Node(7);

  BFSTraversal(head);
  levelWiseTraversal(head);
  iterativePreOrderTraversal(head);

  cout<<endl<<endl;
  iterativeInOrderTraversal(head);
}