#include <bits/stdc++.h>

/*
Sinh viên cần cài đặt hai (02) hàm sau:
Hàm Node* push(Node* root, int n, int newValue): hàm này thêm một giá trị mới vào trong Heap đang có n phần tử và trả về Heap sau khi đã thêm.
Hàm int getMax(Node* root): hàm này trả về giá trị lớn nhất trong Heap. Nếu rỗng trả về -1.
Lưu ý:
Sinh viên chỉ cần cài đặt hai (02) hàm theo yêu cầu.
Không import thêm thư viện.
*/

class Node {
public:
    int data;
    Node* parent;
    Node* left;
    Node* right;

    // Các biến tạm dưới đây có thể dùng để lưu vị trí, kiểm tra nếu sinh viên thấy cần thiết
    bool tempBool1; // Hai biến tạm kiểu boolean có thể dùng cho bất kỳ mục đích gì
    bool tempBool2;
    int tempInt1; // Hai biến tạm kiểu intcó thể dùng cho bất kỳ mục đích gì
    int tempInt2;
    Node* tempNode1; // Hai biến tạm kiểu Node* có thể dùng cho bất kỳ mục đích gì
    Node* tempNode2;

    Node(int data, Node* parent, Node* left, Node* right) {
        this->data = data;
        this->parent = parent;
        this->left = left;
        this->right = right;
    }
};

Node* push(Node* root, int n, int newValue) {
    if (root == nullptr) {
        return new Node(newValue, nullptr, nullptr, nullptr);
    }

    std::queue<Node*> q;
    q.push(root);
    Node* newNode = new Node(newValue, nullptr, nullptr, nullptr);

    while(!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (cur->left == nullptr) {
            cur->left = newNode;
            newNode->parent = cur;
            break;
        } else {
            q.push(cur->left);
        }
        
        if (cur->right == nullptr) {
            cur->right = newNode;
            newNode->parent = cur;
            break;
        } else {
            q.push(cur->right);
        }
    }

    Node* temp = newNode;
    while ((temp->parent != nullptr && temp->data > temp->parent->data)) {
        std::swap(temp->data, temp->parent->data);
        temp = temp->parent;
    }
    return root;

}

int getMax(Node* root) {
    if (root == nullptr) {
        return -1;
    }
    return root->data;
}

int main() {
    Node* root = nullptr;

}