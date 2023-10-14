#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data);

void insert(Node** root, int data);

void preorderTraversal(Node* root);
void inorderTraversal(Node* root);
void postorderTraversal(Node* root);

#endif 
