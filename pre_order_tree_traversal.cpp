#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preOrder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";      // Visit node
    preOrder(root->left);           // Traverse left subtree
    preOrder(root->right);          // Traverse right subtree
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;
    
    return 0;
}