#include <iostream>
#include <algorithm>

// Structure of a Node in BST
struct Node {
    int key;
    Node* left;
    Node* right;
    int size; // Size of subtree rooted at this node

    Node(int k) : key(k), left(nullptr), right(nullptr), size(1) {}
};

// Get size of a node's subtree
int getSize(Node* node) {
    return node ? node->size : 0;
}

// Update size of a node
void updateSize(Node* node) {
    if (node) {
        node->size = getSize(node->left) + getSize(node->right) + 1;
    }
}

// Insert a key into the BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    updateSize(root);
    return root;
}

// Search for a key in the BST
bool search(Node* root, int key) {
    if (!root) return false;
    if (key == root->key) return true;
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Find the minimum node in BST
Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Find the maximum node in BST
Node* findMax(Node* root) {
    while (root && root->right) {
        root = root->right;
    }
    return root;
}

// Delete a key from the BST
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    updateSize(root);
    return root;
}

// Calculate height of the BST
int height(Node* root) {
    if (!root) return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

// Find the rank of a key in BST
int rank(Node* root, int key) {
    if (!root) return 0;
    if (key < root->key) {
        return rank(root->left, key);
    } else if (key > root->key) {
        return 1 + getSize(root->left) + rank(root->right, key);
    } else {
        return getSize(root->left);
    }
}

// Select the k-th smallest key in BST
Node* select(Node* root, int k) {
    if (!root) return nullptr;
    int leftSize = getSize(root->left);
    if (k < leftSize) {
        return select(root->left, k);
    } else if (k > leftSize) {
        return select(root->right, k - leftSize - 1);
    } else {
        return root;
    }
}

// In-order traversal of BST
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Main function to test the BST operations
int main() {
    Node* root = nullptr;

    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // In-order traversal
    std::cout << "In-order Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Search for keys
    std::cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 25: " << (search(root, 25) ? "Found" : "Not Found") << std::endl;

    // Find min and max
    std::cout << "Minimum key: " << findMin(root)->key << std::endl;
    std::cout << "Maximum key: " << findMax(root)->key << std::endl;

    // Delete a key
    root = deleteNode(root, 50);
    std::cout << "After deleting 50, In-order Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Rank and select
    std::cout << "Rank of 40: " << rank(root, 40) << std::endl;
    Node* kthNode = select(root, 2);
    if (kthNode) {
        std::cout << "The 3rd smallest key: " << kthNode->key << std::endl;
    }

    // Height of the BST
    std::cout << "Height of the BST: " << height(root) << std::endl;

    return 0;
}
