#include <iostream>

using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

// bai 1
void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* t = head;
    while(t != nullptr) {
        cout<<t->data<<endl;
        t = t->next;
    }
}

// bai 2
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    if (head == nullptr) {
        return newNode;
    }
    else {
        SinglyLinkedListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

//bai 3
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->next = llist;
    return newNode;
}

//bai4
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    if (position == 0) {
        newNode->next = llist;
        return newNode;
    }
    
    SinglyLinkedListNode* curr = llist;
    for (int i = 0; i < position - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    if (curr != nullptr) {
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return llist;
}

//bai 5
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    SinglyLinkedListNode* curr = llist;
    if (position == 0) {
        SinglyLinkedListNode* temp = llist;
        llist = llist->next;
        delete temp;
        return llist;
    }
    
    for (int i = 0; i < position - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }
    SinglyLinkedListNode* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return llist;
}

//bai 6
void reversePrint(SinglyLinkedListNode* llist) {
    if (llist == nullptr) {
        return;
    }
    reversePrint(llist->next);
    cout << llist->data << endl;
}

//bai 7
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* curr = llist;
    SinglyLinkedListNode* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//bai 8
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    do {
        if (head1->data != head2->data) {
            return false;
        }
        else {
            head1 = head1->next;
            head2 = head2->next;
            if (head1 == nullptr && head2 != nullptr) return false;
            if (head1 != nullptr && head2 == nullptr) return false;
        }
    } while (head1 != nullptr && head2 != nullptr);
    return true;
}

// bai 9
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode d(0);
    SinglyLinkedListNode* tail = &d;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != nullptr) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    return d.next;
}

//bai 10
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* mP = llist;
    SinglyLinkedListNode* rP = llist;

    for (int i = 0; i < positionFromTail + 1; i++) {
        if (rP == nullptr) {
            return -1; 
        }
        rP = rP->next;
    }

    while (rP != nullptr) {
        mP = mP->next;
        rP = rP->next;
    }

    if (mP != nullptr) {
        return mP->data;
    }
    
    return -1; 
}

int main() {
    return 0;
}