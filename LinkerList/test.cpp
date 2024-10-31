#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* rM = llist;
    SinglyLinkedListNode* rP = llist;

    for (int i = 0; i < positionFromTail; i++) {
        if (rP != nullptr) {
            rP = rP->next;
        }
    }

    while (rP != nullptr) {
        rM = rM->next;
        rP = rP->next;
    }

    return rM->data;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int position;
        cin >> position;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = getNode(llist->head, position);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

/*
Given a pointer to the head of a linked list and a specific position, determine the data value at that position. Count backwards from the tail node. The tail is at postion 0, its parent is at 1 and so on.
Example
head refers to 3 -> 2 -> 1 -> 0 -> NULL positionFromTail = 2
Each of the data values matches its distance from the tail. The value 2 is at the desired position.

Function Description

Complete the getNode function in the editor below.

getNode has the following parameters:

SinglyLinkedListNode pointer head: refers to the head of the list
int positionFromTail: the item to retrieve
Returns

int: the value at the desired position

Input Format:
The first line contains an integer t, the number of test cases. 
Each test case has the following format:
The first line contains an integer n, the number of elements in the linked list. 
The next n lines contains an integer, the data value for an element of the linked list. 
The last line contains an integer positionFromTail, the position from the tail to retrieve the value of. 

Sample Input:
2
1
1
0
3
3
2
1
2

Sample Output:
1
3

*/