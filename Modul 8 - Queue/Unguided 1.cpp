#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

const int maksimalQueue = 5;
Queue q;

void initQueue(Queue &q) {
    q.head = nullptr;
    q.tail = nullptr;
}

bool isEmpty(Queue &q) {
    return q.head == nullptr;
}

void enqueueAntrian(Queue &q, string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (q.tail == nullptr) {
        q.head = newNode;
        q.tail = newNode;
    } else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
}

void dequeueAntrian(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = q.head;
        q.head = q.head->next;
        delete temp;

        if (q.head == nullptr) {
            q.tail = nullptr;
        }
    }
}

void viewQueue(Queue &q) {
    cout << "Data antrian teller:" << endl;
    Node* current = q.head;
    int position = 1;

    while (current != nullptr) {
        cout << position << ". " << current->data << endl;
        current = current->next;
        position++;
    }
}

int main() {
    initQueue(q);
    enqueueAntrian(q, "Andi");
    enqueueAntrian(q, "Maya");
    viewQueue(q);
    dequeueAntrian(q);
    viewQueue(q);
 
    return 0;
}