#include <iostream>
#define MAX 1000 

using namespace std;

// Stack use array
struct StackArr {
    int top;
    int arr[MAX];
};

void init(StackArr &s) {
    s.top = -1;
}

void push(StackArr& s, int x) {
    if (s.top >= MAX - 1) {
        cout<<"Stack full!\n";
        return;
    }
    s.arr[s.top++] = x;
}

int pop(StackArr& s) {
    if (s.top < 0) {
        cout<<"Stack empty!\n";
        return -1;
    }
    return s.arr[s.top--];
}

// Stack use Linker List
struct Node {
    int data;
    Node* next;
};

struct StackL {
    Node* top;
};

void init(StackL& s) {
    s.top = nullptr;
}

void push(StackL& s, int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = s.top;
    s.top = newNode;
}

int pop(StackL& s) {
    if (s.top == nullptr) {
        cout<<"Stack empty!\n";
        return -1;
    }
    Node* t = s.top;
    int data = t->data;
    s.top = s.top->next;
    delete t;
    return data;
}

// Queue use Array
struct QueueArr {
    int front;
    int rear;
    int arr[MAX];
};

void init(QueueArr& q) {
    q.front = -1;
    q.rear = -1;
}

void enqueue(QueueArr& q, int x) {
    if (q.rear >= MAX - 1) {
        cout<<"Queue full";
        return;
    }
    if (q.front == -1) {
        q.front = 0;
    }
    q.arr[q.rear++] = x;
}

int dequeue(QueueArr& q) {
    if (q.front == -1 || q.front > q.rear) {
        cout<<"Queue empty!\n";
        return -1;
    }
    int data = q.arr[q.front];
    q.front++;
    return data;
}

// Queue use Linker list
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

    return 0;
}



