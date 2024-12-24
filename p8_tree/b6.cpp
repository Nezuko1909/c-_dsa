#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

int height(node* n) {
    if (n == NULL) {
        return -1;
    }
    return n->ht;
}

int balanceF(node*n) {
    if (n == NULL) {
        return -1;
    }
    return height(n->left) - height(n->right);
}

node* rotateL(node* x) {
    node* y = x->right;
    node* z = y->left;

    y->left = x;
    x->right = z;

    x->ht = max(height(x->left), height(x->right)) + 1;
    y->ht = max(height(y->left), height(y->right)) + 1;

    return y;
}

node* rotateR(node* y) {
    node* x = y->left;
    node* z = x->right;

    x->right = y;
    y->left = z;

    y->ht = max(height(y->left), height(y->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;

    return x;
}

node * insert(node * root,int val) {
    if (root == NULL) {
        node* newNode = new node();
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->ht = 0;
        return newNode;
    }
    //else
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    } else {
        return root;
    }

    root->ht = 1 + max(height(root->left), height(root->right));
    int balance = balanceF(root);

    if (balance > 1 && val < root->left->val) {
        return rotateR(root);
    }
    if (balance < -1 && val > root->right->val) {
        return rotateL(root);
    }

    if (balance > 1 && val > root->left->val) {
        root->left = rotateL(root->left);
        return rotateR(root);
    }
    if (balance < -1 && val < root->right->val) {
        root->right = rotateR(root->right);
        return rotateL(root);
    } 

    return root;
}

