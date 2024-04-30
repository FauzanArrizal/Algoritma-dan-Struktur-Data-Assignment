# <h1 align="center">Laporan Praktikum Modul 6 Linked List</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Single Linked List
Single Linked List (SLL) adalah suatu linked list yang terdiri dari elemen-elemen individu, dimana masing-masing dihubungkan dengan pointer tunggal. Masing-masing elemen terdiri dari dua bagian, yaitu sebuah data dan sebuah pointer yang disebut dengan pointer next. Dengan menggunakan struktur two-member seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya [1].

##### Kekurangan dan Kelebihan Single Linked List: 
###### Kelebihan: 
- Mudah digunakan.
- Tidak membutuhkan banyak memori jika dibandingkan dengan Double Linked List.
- Sangat sesuai untuk aplikasi yang hanya memerlukan akses data satu arah.
###### Kekurangan:
- Proses seperti menambahkan dan menghapus di tengah daftar lebih rumit. 
- Tidak dapat diakses dari sudut pandang yang berlawanan.

#### 2. Double Linked List
Double Linked List (DLL) adalah suatu linked list yang terdiri dari elemen-elemen individu, dimana masing-masing dihubungkan dengan dua pointer, yaitu pointer next dan pointer prev. Double Linked List mempunyai fleksibilitas yang lebih tinggi daripada Single Linked List dalam perpindahan pada list [2].

##### Kekurangan dan Keunggulan Double Linked List: 
###### Keunggulan: 
- Memungkinkan akses data dua arah.
- Lebih mudah untuk melakukan operasi penambahan dan penghapusan di tengah daftar.
###### Kekurangan: 
- Melaksanakannya lebih sulit.
- Dibandingkan dengan Single Linked List, membutuhkan lebih banyak memori.

#### 3. Non-Circular Linked List
Linked list non circular memiliki node header dan tail tanpa hubungan antara dua ujung. Proses penambahan/penghapusan dimulai dari salah satu ujung [1].

#### 4. Circular Linked List
Circular linked list adalah linked list yang memiliki hubungan antara dua ujung. Proses penambahan/penghapusan dimulai dari salah satu ujung.

## Guided 

### 1. SINGLE LINKED LIST NON-CIRCULAR

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```

Output:
![Screenshot (403)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/6e2b8589-ab70-473c-80e0-9bd7fcf20ed7)

Penjelasan:

Kode yang disebutkan di atas digunakan untuk menerapkan Single Linked List Non-Circular. Struktur node program terdiri dari dua komponen: data dan next. Data adalah variabel integer, dan next adalah pointer ke node berikutnya. Deklarasi global node `head` dan node `tail` digunakan untuk menunjukkan node pertama dan terakhir pada daftar yang terhubung. Dengan menggunakan fungsi init(), head dan tail dapat diinisialisasi dengan nilai NULL.

Fungsi `hapusDepan()`, `hapusBelakang()`, dan `hapusTengah()` menambahkan Node baru di depan dan belakang linked list, sementara fungsi `hitungList()` menghitung jumlah Node pada linked list. Fungsi `isEmpty()` mengecek apakah linked list kosong atau tidak. Fungsi `insertDepan()` dan `insertBelakang()` menambahkan Node baru di depan dan belakang linked list, dan fungsi `hapusTengah()` memeriksa validitas posisi yang dimasukkan.

Pemanggilan fungsi-fungsi tersebut dilakukan pada bagian `main()` untuk menguji dan memvalidasi kode program. Fungsi `ubahDepan()`, `ubahTengah()`, dan `ubahBelakang()` mengubah data pada node pada posisi depan, tengah, dan belakang daftar terkait. Fungsi `clearList()` menghapus semua node pada daftar terkait, dan fungsi `tampil()` menampilkan data pada semua node pada daftar terkait.


### 2. DOUBLE LINKED LIST

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2: {
            list.pop();
            break;
        }
        case 3: {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData, newData);
            if (!updated) {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4: {
            list.deleteAll();
            break;
        }
        case 5: {
            list.display();
            break;
        }
        case 6: {
            return 0;
        }
        default: {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
```
Output:

![Screenshot (404)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/8838e59c-e025-43c2-831d-7efc4fad932c)

![Screenshot (405)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/5b033240-ca36-4f65-92b6-52cfa9e29889)



Penjelasan:

Program di atas merupakan implementasi dari double linked list dalam C++. Ini terdiri dari dua kelas: Node yang mewakili simpul dalam linked list, dan DoublyLinkedList yang merupakan representasi keseluruhan dari linked list. Setiap simpul memiliki tiga atribut: data (untuk menyimpan nilai data), prev (sebagai pointer ke simpul sebelumnya), dan next (sebagai pointer ke simpul berikutnya). Kelas DoublyLinkedList memiliki atribut head dan tail yang menunjukkan awal dan akhir dari linked list. Metode-metode dalam kelas DoublyLinkedList termasuk push (untuk menambahkan data di depan linked list), pop (untuk menghapus data dari depan linked list), update (untuk memperbarui nilai data tertentu dalam linked list), deleteAll (untuk menghapus semua data dalam linked list), dan display (untuk menampilkan semua data dalam linked list). Di dalam fungsi main, program memberikan opsi kepada pengguna untuk menambah, menghapus, memperbarui, menampilkan, menghapus semua data, atau keluar dari program. Sesuai dengan pilihan yang dibuat, program akan memanggil metode yang sesuai dari kelas DoublyLinkedList.


### 3.

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan apakah list kosong
int isEmpty() {
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    buatNode(data);
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    buatNode(data);
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;
        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;
        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }
            while (tail->next != hapus) {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;
        while (hapus != head) {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;
        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Output:
![Screenshot (406)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/dd6a577b-feb7-4b2d-b5dd-6e24f7c2713c)

Penjelasan:

Kode di atas menunjukkan implementasi list non-circular single-linked list dalam C++. Struktur program mirip dengan linked list, dengan beberapa fungsi utama seperti penambahan, penghapusan, pengubahan, dan penampilan elemen. Selain itu, program dapat melakukan berbagai operasi pada linked list, seperti penambahan, penghapusan, pengubahan, dan penampilan elemen. Pada fungsi clearList, program menghapus semua node dalam linked list dengan mengosongkan memori dan Program melakukan operasi seperti menambahkan, menghapus, mengubah, dan menampilkan elemen dalam daftar terkait untuk menguji fungsionalitasnya setelah menginisialisasi daftar terkait dengan `init()`.

## Unguided 

#### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 

#### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 

#### 3. Lakukan perintah

```C++
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
```
#### Output:
No. 1
![Screenshot (408)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/b1bb1848-218c-446a-8624-513349a00d02)

No.2
![Screenshot (409)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/36f380b3-7449-4e30-a8f4-7f3986f04050)


No. 3
![Screenshot (407)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/3187290b-4800-4a51-91f4-071c64afd30b)

Penjelasan:

Program tersebut merupakan implementasi dalam bahasa C++ yang menggunakan single linked list non-circular untuk melakukan berbagai operasi seperti penambahan, penghapusan, dan pembaruan data dalam linked list. Struktur data Node didefinisikan dengan dua atribut data bertipe string dan satu pointer next. Fungsi-fungsi yang disediakan meliputi inisialisasi, pengecekan apakah linked list kosong, penambahan data di depan, di belakang, dan di tengah, penghapusan data di depan, di belakang, dan di tengah, serta menampilkan seluruh data dalam linked list. Terdapat juga fungsi menu yang memberikan opsi operasi kepada pengguna untuk memanipulasi data dalam linked list. Program ini menggunakan tampilan yang terstruktur dengan menggunakan tabel untuk memberikan informasi yang lebih terorganisir.


## Kesimpulan
Searching merupakan proses pencarian Dari uraian mengenai single linked list (SLL), double linked list (DLL), serta linked list non-circular dan circular, dapat disimpulkan bahwa setiap jenis linked list memiliki kelebihan dan kekurangan masing-masing. SLL memiliki kemudahan penggunaan dan kebutuhan memori yang relatif lebih sedikit, tetapi proses penambahan dan penghapusan di tengah daftar menjadi lebih rumit. Sebaliknya, DLL memungkinkan akses data dua arah dan lebih mudah melakukan operasi penambahan dan penghapusan di tengah daftar, namun membutuhkan lebih banyak memori dan proses implementasinya lebih sulit. Selain itu, perbedaan antara linked list non-circular dan circular terletak pada adanya hubungan antara dua ujung pada circular linked list, yang dapat mempengaruhi proses penambahan dan penghapusan data. Dalam pemilihan jenis linked list, perlu dipertimbangkan kebutuhan spesifik aplikasi dan kompleksitas operasi yang akan dilakukan.

## Referensi

[1] *Senarai Berantai (Linked List)*. Available:
https://yuliana.lecturer.pens.ac.id/Struktur%20Data%20C/Teori%20SD%20-%20pdf/Data%20Structure%20-%20Bab%202.pdf

[2] Parveen Kumar, Neha Singh, & Prashant Kumar. *Applications of Single and Double Linked Lists in Modern Programming Languages and Applications. Association for Computing Machinery (ACM)*. 2020.
