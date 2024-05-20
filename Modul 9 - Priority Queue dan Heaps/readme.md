# <h1 align="center">Laporan Praktikum Modul 9 Priority Queue dan Heaps</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Priority Queue dan Heaps

Antrian prioritas (priority queue) adalah suatu struktur data yang memungkinkan penambahan elemen baru dengan prioritas yang berbeda-beda. Elemen yang memiliki prioritas tertinggi akan pertama diambil. Heaps adalah suatu struktur data yang digunakan untuk implementasi antrian prioritas. Heaps dapat berupa max-heap atau min-heap, tergantung pada prioritas yang ingin diwujudkan. Max-heap mengambil elemen dengan prioritas tertinggi, sedangkan min-heap mengambil elemen dengan prioritas terendah [1].

#### 2. Cara Kerja Priority Queue dan Heaps

Operasi yang dapat dilakukan pada priority queue dan heaps meliputi:

- Insertion: Menambahkan elemen baru ke dalam antrian dengan prioritas yang diberikan. Elemen baru akan ditempatkan di ujung belakang antrian dan kemudian diurutkan untuk mempertahankan properti antrian prioritas.
- Deletion: Menghapus elemen yang memiliki prioritas tertinggi dari antrian. Elemen yang dihapus akan digantikan oleh elemen terakhir di antrian, dan kemudian diurutkan untuk mempertahankan properti antrian prioritas.
- Extract Min-Max: Mengembalikan dan menghapus elemen dengan prioritas tertinggi (max-heap) atau terendah (min-heap) dari antrian. Elemen yang dihapus akan digantikan oleh elemen terakhir di antrian, dan kemudian diurutkan untuk mempertahankan properti antrian prioritas [2] [3].

#### 3. Kelebihan dan Kekurangan Priority Queue dan Heaps

Kelebihan:
- Efisiensi: Operasi insertion dan deletion dapat dilakukan dengan kompleksitas waktu O(log N), membuatnya lebih efisien dibandingkan dengan struktur data lain yang memiliki kompleksitas waktu O(N) [4].
- Pengaturan Antrian: Berguna untuk mengatur dan mengelola antrian tugas atau proses, memastikan bahwa tugas diproses sesuai dengan urutan masuknya [4].
- Implementasi Algoritma: Sering digunakan sebagai bagian dari berbagai algoritma, seperti pencarian Breadth-First Search, pemrosesan data, dan algoritma lain yang membutuhkan struktur data FIFO [4].

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
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";
    
    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
```

Output:
![Screenshot (462)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/e1e23ced-3d10-489f-a42b-ecb5a65f4602)

Penjelasan:

Program ini mengimplementasikan antrean prioritas dengan heap maksimum menggunakan array dan menyediakan fungsi-fungsi untuk operasi heap umum seperti penyisipan `insert`, ekstraksi elemen maksimum `extractMax`, perubahan prioritas `changePriority`, dan penghapusan elemen `remove`. Heap dipertahankan melalui fungsi pembantu `shiftUp` dan `shiftDown` untuk memastikan properti heap maksimum terjaga setelah setiap operasi. Fungsi utama mendemonstrasikan penggunaan operasi-operasi ini dengan menyisipkan beberapa elemen ke dalam heap, mengekstrak elemen maksimum, mengubah prioritas sebuah elemen, dan menghapus sebuah elemen, sambil mencetak keadaan antrean prioritas setelah setiap operasi untuk memverifikasi kebenarannya.

## Unguided 

#### 1.	Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

```C++
#include <iostream>
#include <algorithm>

using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    
    cout << "Masukkan elemen-elemen: ";
    for (int i = 0; i < n; ++i) {
        int elemen;
        cin >> elemen;
        insert(elemen);
    }

    cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node dengan prioritas maksimum : " << extractMax() << "\n";
    
    cout << "Priority queue setelah ekstraksi maksimum : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    int indeks, prioritas;
    cout << "Masukkan indeks dan prioritas baru: ";
    cin >> indeks >> prioritas;
    changePriority(indeks, prioritas);
    
    cout << "Priority queue setelah perubahan prioritas : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Masukkan indeks yang ingin dihapus: ";
    cin >> indeks;
    remove(indeks);
    
    cout << "Priority queue setelah penghapusan elemen : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}
```
#### Output:
![Screenshot (463)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/771d9209-1ed2-4083-b062-417fbd967546)

Penjelasan:

Program ini mengimplementasikan antrean prioritas dengan heap maksimum menggunakan array dan menyediakan fungsi untuk operasi-operasi umum seperti penyisipan `insert`, ekstraksi elemen maksimum `extractMax`, perubahan prioritas `changePriority`, dan penghapusan elemen `remove`. Heap dijaga melalui fungsi `shiftUp` dan `shiftDown` untuk memastikan sifat heap maksimum tetap terjaga setelah setiap operasi. Dalam fungsi utama, program meminta pengguna untuk memasukkan sejumlah elemen, lalu menampilkan isi heap setelah setiap operasi, termasuk penyisipan elemen, ekstraksi elemen dengan prioritas tertinggi, perubahan prioritas elemen, dan penghapusan elemen. Pengguna juga diminta untuk memasukkan indeks dan prioritas baru saat mengubah prioritas serta indeks elemen yang ingin dihapus. Program ini mempermudah pengelolaan antrean prioritas dengan memberikan antarmuka interaktif untuk melihat perubahan pada heap setelah setiap operasi.

## Kesimpulan

Antrian prioritas (priority queue) adalah struktur data yang memungkinkan pengelolaan elemen dengan prioritas berbeda, di mana elemen dengan prioritas tertinggi akan diambil pertama. Implementasi antrian prioritas sering menggunakan heap, baik max-heap untuk prioritas tertinggi maupun min-heap untuk prioritas terendah. Operasi utama pada heap meliputi penyisipan, penghapusan, dan ekstraksi elemen dengan prioritas tertinggi atau terendah, dengan efisiensi waktu O(log N). Struktur data ini berguna dalam pengaturan antrian tugas, implementasi algoritma seperti Breadth-First Search dan pencarian jalur terpendek, serta aplikasi lain yang memerlukan pengelolaan data secara efisien. Namun, kelemahannya termasuk potensi ketidakadilan bagi data yang terakhir masuk dan penggunaan memori yang lebih besar jika diimplementasikan dengan linked list. Algoritma yang sering digunakan dengan queue mencakup FIFO, LIFO, dan priority queue, serta berbagai algoritma pencarian dan penjadwalan.

## Referensi

[1] Andri Heryandi. *Heap dan Operasinya*. Available: https://repository.unikom.ac.id/36115/1/Bab%20XI%20-%20Heap.pdf

[2] Antony Pranata. *Pemrograman Borland C++*. Andi Offset. Yogyakarta

[3] Moh. Sjukani. *Algoritma dan Struktur data dengan C, C++, dan Java*. Mitra Wacana Media. 2005

[4] Dewi. *Pengertian, Jenis-jenis, Contoh, Kelebihan dan Kekurangan Struktur Data*. 2019. Available: https://dewikhrnnsa.blogspot.com/2019/02/pengertian-dan-jenis-jenis-struktur.html

[5] Sianipar. *Struktur Data C++ dengan Pemograman Generik*. Yogyakarta: Andi Yogyakarta. 2015

