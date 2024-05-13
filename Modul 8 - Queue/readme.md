# <h1 align="center">Laporan Praktikum Modul 8 Queue</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Queue

Antrian adalah suatu kumpulan data yang penambahan elemen hanya bisa dilakukan pada suatu ujung (disebut dengan sisi belakang atau rear), dan penghapusan (pengambilan elemen) dilakukan lewat ujung lain (disebut dengan sisi depan atau front). Seperti kita ketahui, tumpukan menggunakan prinsip "masuk terakhir keluar pertama" atau LIFO (Last In First Out), maka pada antrian prinsip yang digunakan adalah "masuk pertama keluar pertama" atau FIFO (First In First Out). Dengan kata lain, urutan keluar elemen akan sama dengan urutan masuknya. 

Antrian banyak kita jumpai dalam kehidupan sehari-hari. Mobil-mobil yang antri di pintu jalan tol akan membentuk antrian; orang-orang yang membeli tiket untuk menyaksikan film akan membentuk antrian; para nasabah bank yang melakukan transaksi (mengambil dan menabung) membentuk antrian, dan contoh-contoh lain yang banyak kita jumpai dalam kehidupan sehari-hari. [1].

#### 2. Cara Kerja Queue

Queue dalam program C++ beroperasi dengan prinsip "First In First Out" (FIFO), yang berarti elemen pertama yang dimasukkan ke dalam queue akan pertama keluar. Implementasi queue dalam C++ melibatkan penggunaan struktur data yang memungkinkan penambahan elemen baru di ujung belakang dan penghapusan elemen di ujung depan. Dalam implementasi, queue dapat dibuat menggunakan struktur data yang memiliki atribut untuk menyimpan data dan indeks untuk menunjukkan posisi elemen dalam queue. Operasi queue seperti create, is empty, is full, enqueue, dan dequeue dapat dilakukan dengan menggunakan fungsi yang sesuai [2] [3].

#### 3. Kelebihan dan Kekurangan Queue

Kelebihan:
- Urutan Data: Mengatur dan memproses data berdasarkan prinsip antrian, sehingga elemen pertama yang dimasukkan akan pertama keluar [4].
- Pengaturan Antrian: Berguna untuk mengatur dan mengelola antrian tugas atau proses, memastikan bahwa tugas diproses sesuai dengan urutan masuknya [4].
- Implementasi Algoritma: Sering digunakan sebagai bagian dari berbagai algoritma, seperti pencarian Breadth-First Search, pemrosesan data, dan algoritma lain yang membutuhkan struktur data FIFO [4].
- Efisiensi: Dapat mengolah data berjumlah besar dengan efisiensi, dengan perintah seperti penyisipan dan penghapusan yang dapat dilakukan dengan mudah karena berurutan [4].
- Struktur Data yang Fleksibel: Dapat diimplementasikan dengan mudah menggunakan berbagai struktur data dasar seperti array atau linked list, membuatnya sesuatu yang fleksibel dan dapat disesuaikan dengan kebutuhan aplikasi atau algoritma tertentu [4].


Kekurangan:
- Data yang Terakhir Masuk: Data yang terakhir masuk mungkin tidak dilayani jika waktu pelayanan habis [4].
- Implementasi Linked List: Implementasi queue menggunakan linked list memerlukan memori yang lebih banyak dan dapat menjadi lambat karena setiap elemen hanya dapat diakses secara sekuensial [4].

#### 4. Algoritma yang Sering Digunakan dengan Queue

- First In First Out (FIFO): Algoritma ini mengatur urutan elemen dalam queue dengan cara elemen pertama yang dimasukkan akan pertama keluar. Algoritma ini digunakan dalam aplikasi seperti sistem operasi, jaringan, dan aplikasi lain yang memerlukan pengelolaan data secara efisien dan cepat [5].

- Last In First Out (LIFO): Algoritma ini mengatur urutan elemen dalam queue dengan cara elemen terakhir yang dimasukkan akan pertama keluar. Algoritma ini digunakan dalam aplikasi seperti sistem operasi, jaringan, dan aplikasi lain yang memerlukan pengelolaan data secara efisien dan cepat [5].

- Priority Queue: Algoritma ini mengatur urutan elemen dalam queue dengan cara elemen yang memiliki prioritas tertinggi akan diambil terlebih dahulu. Algoritma ini digunakan dalam aplikasi seperti sistem operasi, jaringan, dan aplikasi lain yang memerlukan pengelolaan data secara efisien dan cepat [5].

- Double-ended Queue (Dequeue): Algoritma ini mengatur urutan elemen dalam queue dengan cara elemen dapat ditambahkan atau dihapus dari kedua ujung antrean. Algoritma ini digunakan dalam aplikasi seperti sistem operasi, jaringan, dan aplikasi lain yang memerlukan pengelolaan data secara efisien dan cepat [5].

- Breadth-First Search (BFS): Algoritma ini digunakan dalam aplikasi seperti pencarian dalam struktur data yang kompleks, seperti graf dan treet. Algoritma ini menggunakan queue untuk menemukan elemen yang paling dekat dengan sumber [5].

- Depth-First Search (DFS): Algoritma ini digunakan dalam aplikasi seperti pencarian dalam struktur data yang kompleks, seperti graf dan treet. Algoritma ini menggunakan stack untuk menemukan elemen yang paling dekat dengan sumber [5].

- Topological Sort: Algoritma ini digunakan dalam aplikasi seperti pengelolaan graf dan treet. Algoritma ini menggunakan queue untuk mengatur urutan elemen dalam graf dan treet [5].

- Shortest Path Algorithm: Algoritma ini digunakan dalam aplikasi seperti pengelolaan jaringan dan graf. Algoritma ini menggunakan queue untuk menemukan jalur terpendek antara dua titik dalam graf [5].

- Job Scheduling: Algoritma ini digunakan dalam aplikasi seperti pengelolaan sumber daya dan penjadwalan tugas. Algoritma ini menggunakan queue untuk mengatur urutan tugas yang akan dijalankan [5].

- Network Routing: Algoritma ini digunakan dalam aplikasi seperti pengelolaan jaringan dan routing pesan. Algoritma ini menggunakan queue untuk mengatur urutan pesan yang akan dijalankan [5].

## Guided

### 1.
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
```

Output:
![Screenshot (423)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/0fd547ea-3d42-4fba-ab7e-0c61c44679f7)

Penjelasan:

Kode tersebut menunjukkan simulasi sistem antrian yang sederhana untuk teller, termasuk fungsi-fungsi untuk menambah, menghapus, memeriksa apakah antrian penuh atau kosong, menghitung jumlah elemen dalam antrian, membersihkan antrian, dan menampilkan status antrian terkini. Program ini menggunakan variabel global untuk menyimpan ukuran maksimum antrian, penunjuk depan (front), penunjuk belakang (back), dan array untuk elemen-elemen antrian. Dalam berbagai fungsi seperti `enqueueAntrian()` untuk menambahkan elemen, `dequeueAntrian()` untuk menghapus elemen, penunjuk belakang dan depan diperbarui sesuai dengan operasi yang dilakukan. Fungsi `viewQueue()` digunakan untuk menampilkan status antrian saat ini. Dalam fungsi `main()`, elemen "Andi" dan "Maya" dimasukkan ke antrian, status antrian ditampilkan, dan jumlah elemen dihitung. Selanjutnya, elemen dihapus dari antrian, status antrian diperbarui, dan jumlah elemen dicetak kembali. Terakhir, antrian dikosongkan, status antrian ditampilkan kembali, dan jumlah elemen dihitung sebelum program selesai dijalankan.

## Unguided 

#### 1.	Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
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
```
#### Output:
![Screenshot (424)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/5a7f67f3-eb7e-46e3-9f05-9e59b4c90a27)


Penjelasan:

Kode tersebut adalah queue menggunakan linked list, terdiri dari Node yang menyimpan data dan pointer ke Node berikutnya, serta Queue dengan pointer kepala (head) dan ekor (tail) antrian. Fungsi `initQueue(Queue &q)` digunakan untuk inisialisasi antrian dengan mengatur pointer head dan tail menjadi nullptr, sementara `isEmpty(Queue &q)` mengembalikan nilai true jika antrian kosong. Untuk menambahkan elemen ke antrian, fungsi `enqueueAntrian(Queue &q, string data)` digunakan dengan menyesuaikan pointer tail, dan untuk menghapus elemen pertama dari antrian, digunakan fungsi `dequeueAntrian(Queue &q)`. Fungsi `viewQueue(Queue &q)` digunakan untuk menampilkan elemen antrian. Pada fungsi `main()`, antrian diinisialisasi, elemen dimasukkan, status antrian ditampilkan, elemen dihapus, dan status antrian kembali ditampilkan sebelum program selesai dieksekusi.


#### 2.	Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
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
```
Output:
![Screenshot (425)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/200fe995-4bd9-4037-a7d8-e1916b35b29c)


Penjelasan:

Kode tersebut mengaplikasikan struktur antrian (queue) dengan menggunakan linked list untuk menyimpan informasi mahasiswa seperti nama dan NIM. Node menyimpan data nama dan NIM serta pointer next, sementara Queue memuat pointer head dan tail. Fungsi `initQueue(Queue &q)` bertugas menginisialisasi antrian, sedangkan `isEmpty(Queue &q)` digunakan untuk memeriksa keberadaan elemen dalam antrian. Fungsi `enqueueAntrian(Queue &q, string nama, string nim)` menambahkan data mahasiswa ke antrian, dan `dequeueAntrian(Queue &q)` menghapus data pertama dari antrian jika tidak kosong. Untuk menampilkan data mahasiswa dalam antrian, digunakan fungsi `viewQueue(Queue &q)`. Pada bagian `main()`, pengguna diminta untuk memasukkan informasi mahasiswa, yang nantinya akan disimpan dalam antrian untuk proses selanjutnya.

## Kesimpulan

Queue adalah struktur data yang memungkinkan penambahan elemen hanya di ujung belakang dan penghapusan elemen hanya di ujung depan, dengan prinsip operasi "First In First Out" (FIFO). Queue digunakan dalam berbagai aplikasi, seperti pengelolaan antrian, pengelolaan data, dan algoritma lain yang memerlukan pengelolaan data secara efisien dan cepat. Kelebihan queue meliputi pengaturan antrian, implementasi algoritma, efisiensi, dan struktur data yang fleksibel, namun kekurangannya meliputi data yang terakhir masuk mungkin tidak dilayani jika waktu pelayanan habis dan implementasi linked list memerlukan memori yang lebih banyak dan dapat menjadi lambat. Queue digunakan dalam berbagai algoritma, seperti First In First Out, Last In First Out, Priority Queue, Double-ended Queue, Breadth-First Search, Depth-First Search, Topological Sort, Shortest Path Algorithm, Job Scheduling, dan Network Routing.

## Referensi

[1] Wanra Tarigan. *Algoritma Pemrograman dan Struktur Data*. Eureka Media Aksara. 2022

[2] Antony Pranata. *Pemrograman Borland C++*. Andi Offset. Yogyakarta

[3] Moh. Sjukani. *Algoritma dan Struktur data dengan C, C++, dan Java*. Mitra Wacana Media. 2005

[4] Dewi. *Pengertian, Jenis-jenis, Contoh, Kelebihan dan Kekurangan Struktur Data*. 2019. Available: https://dewikhrnnsa.blogspot.com/2019/02/pengertian-dan-jenis-jenis-struktur.html

[5] Sianipar. *Struktur Data C++ dengan Pemograman Generik*. Yogyakarta: Andi Yogyakarta. 2015

