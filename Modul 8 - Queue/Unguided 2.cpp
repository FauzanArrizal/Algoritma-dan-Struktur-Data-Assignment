#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
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

void enqueueAntrian(Queue &q, string nama, string nim) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->nim = nim;
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
    cout << "Data antrian mahasiswa:" << endl;
    Node* current = q.head;
    int position = 1;

    while (current != nullptr) {
        cout << position << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
        position++;
    }
}

int main() {
    initQueue(q);

    string nama, nim;

    cout << "Masukkan Nama Mahasiswa dan NIM:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        cout << "Nama Mahasiswa ke-" << i + 1 << ": ";
        cin >> nama;
        cout << "NIM Mahasiswa ke-" << i + 1 << ": ";
        cin >> nim;
        enqueueAntrian(q, nama, nim);
    }

    viewQueue(q);
    
    dequeueAntrian(q);
    
    cout << "\nSetelah queue:" << endl;
    viewQueue(q);

    return 0;
}