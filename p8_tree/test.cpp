#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insertRandom(Node* root, int data) {
    if (root == nullptr) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* cur = new Node();
    if (rand() % 2 == 0) {
        cur = insertRandom(root->left, data);
        root->left = cur;
    } else {
        cur = insertRandom(root->right, data);
        root->right = cur;
    }
    return root;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* cur = new Node();
    if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
    }
    else { 
        cur = insert (root->right, data);
        root->right = cur;
    }
    return root;
}

int getHeight(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    return 1 + max(left, right);
}

void readTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    readTree(root->left);
    cout<<root->data<<" ";
    readTree(root->right);
}

void GetTreeToArr(Node* root, vector<int> &vec) {
    if (root == nullptr) {
        return;
    }
    GetTreeToArr(root->left, vec);
    vec.push_back(root->data);
    GetTreeToArr(root->right, vec);
}

int main() {
    srand(time(nullptr));
    int n;
    cin>>n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin>>data;
        root = insertRandom(root, data);
    }

    //cout<<getHeight(root)<<"\n";
    cout<<"Cay duoc tao ra:\n";
    readTree(root);

    vector<int> getTree = {};
    GetTreeToArr(root, getTree);

    cout<<"\nTree trong array:\n";
    for (auto x : getTree) {
        cout<<x<<" ";
    }

    Node* newRoot = nullptr;

    for (int i = 0; i < getTree.size(); i++) {
        newRoot = insert(newRoot, getTree[i]);
    }

    cout<<"\nCay sau khi chuyen sang cay nhi phan:\n";
    readTree(newRoot);

    return 0;
}

/**Example test:

15
1 3 2 5 4 6 7 9 8 11 13 12 10 15 14
output: 9

6
4 1 8 10 9 3
out: 3

7
3 5 2 1 4 6 7
out 3

1
10
out: 0

 */
