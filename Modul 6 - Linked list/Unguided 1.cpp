#include <iostream>
using namespace std;

// Definisi Node
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Inisialisasi Head
Node* head = NULL;

// Fungsi untuk menambahkan data di depan
void tambahDepan(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = head;
    head = newNode;
    cout << "Data telah ditambahkan" << endl;
}

// Fungsi untuk menambahkan data di belakang
void tambahBelakang(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Data telah ditambahkan" << endl;
}

// Fungsi untuk menambahkan data di tengah
void tambahTengah(string nama, string nim, int posisi) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;

    if (posisi == 1 || head == NULL) {
        newNode->next = head;
        head = newNode;
        cout << "Data telah ditambahkan" << endl;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < posisi - 1; i++) {
        if (temp->next == NULL) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Data telah ditambahkan" << endl;
}

// Fungsi untuk mengubah data di depan
void ubahDepan(string nama, string nim) {
    if (head != NULL) {
        head->nama = nama;
        head->nim = nim;
        cout << "Data telah diubah" << endl;
    } else {
        cout << "Linked list kosong" << endl;
    }
}

// Fungsi untuk mengubah data di belakang
void ubahBelakang(string nama, string nim) {
    if (head != NULL) {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->nama = nama;
        temp->nim = nim;
        cout << "Data telah diubah" << endl;
    } else {
        cout << "Linked list kosong" << endl;
    }
}

// Fungsi untuk mengubah data di tengah
void ubahTengah(string nama, string nim, int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 1; i < posisi; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp != NULL) {
            temp->nama = nama;
            temp->nim = nim;
            cout << "Data telah diubah" << endl;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "Linked list kosong" << endl;
    }
}

// Fungsi untuk menghapus data di depan
void hapusDepan() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "Linked list kosong" << endl;
    }
}

// Fungsi untuk menghapus data di belakang
void hapusBelakang() {
    if (head != NULL) {
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "Linked list kosong" << endl;
    }
}

// Fungsi untuk menghapus data di tengah
void hapusTengah(int posisi) {
    if (head != NULL) {
        if (posisi == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Data berhasil dihapus" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            if (temp->next == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->next != NULL) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Data berhasil dihapus" << endl;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "Linked list kosong" << endl;
    }
}

// Fungsi untuk menghapus seluruh linked list
void hapusList() {
    Node* temp = head;
    Node* nextNode;

    while (temp != NULL) {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
    cout << "Seluruh data berhasil dihapus" << endl;
}

// Fungsi untuk menampilkan data
void tampilkanData() {
    cout << "===========================================================" << endl;
    cout << "                       DATA MAHASISWA                      " << endl;
    cout << "===========================================================" << endl;
    cout << "NAMA\t\tNIM" << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << "\t\t" << temp->nim << endl;
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    int operasi, posisi;
    string nama, nim;

    do {
        cout << "===========================================================" << endl;
        cout << "         PROGRAM SINGLE LINKED LIST NON-CIRCULAR           " << endl;
        cout << "===========================================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "===========================================================" << endl;
        cout << "Pilih Operasi: ";
        cin >> operasi;

        switch (operasi) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                tambahDepan(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                tambahTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "Masukkan Nama Baru: ";
                cin >> nama;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                ubahDepan(nama, nim);
                break;
            case 5:
                cout << "Masukkan Nama Baru: ";
                cin >> nama;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                cout << "Masukkan Nama Baru: ";
                cin >> nama;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                ubahTengah(nama, nim, posisi);
                break;
            case 7:
                hapusDepan();
                break;
            case 8:
                hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                hapusTengah(posisi);
                break;
            case 10:
                hapusList();
                break;
            case 11:
                tampilkanData();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Operasi tidak valid." << endl;
        }
    } while (operasi != 0);

    return 0;
}
