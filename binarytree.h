#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data);

// Function to insert a node into the binary tree
void insert(Node** root, int data);

// Function to (in-order traversal)
void preorderTraversal(Node* root);
void inorderTraversal(Node* root);
void postorderTraversal(Node* root);

#endif // TREE_H
