#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct QueueL {
    Node* front;
    Node* rear;
};

void init(QueueL& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

void enqueue(QueueL& q, int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    
    if (q.rear == nullptr) {
        q.front = newNode;
        q.rear= newNode;
        return;
    }

    q.rear->next = newNode;
    q.rear = newNode;
}

int dequeue(QueueL& q) {
    if (q.front == nullptr) {
        cout<<"Queue empty!\n";
        return -1;
    }

    Node* t = q.front;
    int data = t->data;
    q.front = q.front->next;

    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    delete t;
    return data;
}

int main() {
    int req;
    cin>>req;

    QueueL queue;
    init(queue);

    while (req > 0) {
        int op;
        cin>>op;
        if (op == 1) {
            int val;
            cin>>val;
            enqueue(queue, val);
        } 
        else if (op == 2) {
            dequeue(queue);
        }
        else if (op == 3) {
            cout<<queue.front->data<<"\n";
        }
        req--;
    }
}