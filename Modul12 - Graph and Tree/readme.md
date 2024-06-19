# <h1 align="center">Laporan Praktikum Modul 12 Graph and Tree</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Graph
Graph adalah struktur data yang tidak berdekatan (non-linier) yang terdiri dari simpul (verteks) dan sisi (edge) untuk merepresentasikan hubungan antar data. Simpul menyimpan data, sedangkan sisi menghubungkan antar simpul. Graph banyak digunakan untuk menyelesaikan masalah dalam kehidupan nyata seperti jaringan sensor nirkabel dan jejaring sosial. Pada jejaring sosial, pengguna diwakili oleh simpul dan hubungan pertemanan diwakili oleh sisi. [1].

#### 2. Jenis Graph

Berdasarkan ada tidaknya gelang (loop) maupun sisi ganda pada suatu graf, maka graf digolongkan menjadi dua jenis yaitu graf sederhana dan graf tidak sederhana.

- Graf sederhana (simple graph) adalah graf yang tidak memiliki gelang dan sisi ganda. Graf tidak sederhana/multigraf (unsimple graph/ multigraph) adalah graf yang memiliki gelang dan atau sisi ganda [2].

Berdasarkan orientasi arah pada sisi, maka secara umum graf dibedakan menjadi graf tak berarah dan graf berarah [2].

- Graf tak-berarah (undirected graph) adalah graf yang sisinya tidak mempunyai orientasi arah. Graf berarah (directed graph atau digraph) adalah graf yang setiap sisinya diberikan orientasi arah [2].

- Graf lengkap (complete graph) adalah graf sederhana dimana setiap pasang simpul yang berbeda terhubung oleh sebuah sisi. Graf lengkap dengan n buah simpul dilambangkan dengan K. 
Jumlah sisi pada graf lengkap yang terdiri dari 1 buah simpul adalah
n(n-1)/2.

- Graf kosong (trivial) adalah graf yang tidak memiliki sisi [2].

- Graf berbobot (weighted graph) adalah graf yang setiap sisinya diberi sebuah harga (bobot) [2].

#### 3. Kelebihan dan Kekurangan Rekursif

Kelebihan Rekursif:
- Graph membantu dalam mengatur data.
- Graph digunakan untuk mengimplementasikan algoritma seperti DFS dan BFS.
- Dengan menggunakan graph kita dapat dengan mudah menemukan jalur terpendek dan tetangga dari node.
- Karena strukturnya yang non-linier, membantu dalam memahami masalah yang kompleks dan visualisasinya.

Kekurangan Grap:

- Memiliki kompleksitas memori yang besar.
- Graph menggunakan banyak pointer yang bisa rumit untuk ditangani.
- Jika graph direpresentasikan dengan adjacency matrix maka edge tidak memungkinkan untuk sejajar dan operasi perkalian graph juga sulit dilakukan.


## Guided

### 1.
```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}   
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

Output:
![Screenshot (491)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/c45f7fa9-3040-48d3-898f-bd9fd2740ad6)

Penjelasan:

 Program ini menampilkan hubungan antar tujuh kota di Jawa Barat dan Jawa Tengah dalam bentuk graf. Setiap kota diwakili oleh simpul, dan jarak antar kota diwakili oleh bobot pada tepi yang menghubungkan simpul-simpul tersebut. Fungsi tampilGraph() memvisualisasikan graf ini dengan mencetak nama kota dan kota yang terhubung dengannya beserta jaraknya.

### 2.
```C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    TNode (int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder (node->left);
        preOrder (node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder (node->left);
        cout << node->data << " ";
        inOrder (node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        preOrder (node->left);
        preOrder (node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;

    seven->right = nine;

    one->left = zero;

    one->right = five;

    nine->left = eight;

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}
```

Output:
![Screenshot (492)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/780f3ba7-ae5e-4fc7-a196-9e1dd3865064)

Penjelasan:

Program ini ini membangun struktur pohon biner dan menunjukkan cara menjelajahinya dengan urutan yang berbeda. Pohon ini menyimpan nilai integer di setiap node dan memiliki anak di kiri dan kanan.

Tiga fungsi traversal diimplementasikan:

- Preorder: Kunjungi root, lalu kiri, lalu kanan.
- Inorder: Kunjungi kiri, lalu root, lalu kanan.
- Postorder: Kunjungi kiri, lalu kanan, lalu root.

Program ini membuat contoh pohon biner dan menerapkan setiap fungsi traversal, mencetak nilai node yang dikunjungi dalam urutan yang sesuai. Ini memungkinkan Anda untuk menjelajahi pohon dengan berbagai cara.

## Unguided 

#### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

struct Kota {
    char nama[20];
    int jarak[10];
};

int main() {
    int n;
    cout << "Masukkan Jumlah Simpul: ";
    cin >> n;
    
    Kota kota[n];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan Nama Simpul Ke-" << i + 1 << ": ";
        cin >> kota[i].nama;
    }
    
    cout << "Masukkan Bobot Antar Simpul" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << kota[i].nama << "--->" << kota[j].nama << " = ";
            cin >> kota[i].jarak[j];
        }
    }
    
    cout << endl;

    // Header Kolom
    cout << setw(8) << "";
    for (int i = 0; i < n; i++) {
        cout << setw(8) << kota[i].nama;
    }
    cout << endl;

    // Matriks Bobot
    for (int i = 0; i < n; i++) {
        cout << setw(8) << kota[i].nama;
        for (int j = 0; j < n; j++) {
            cout << setw(8) << kota[i].jarak[j];
        }
        cout << endl;
    }
    
    cout << endl << "Proses Selesai dengan Kode 0 (0x0)   Waktu Eksekusi: ";

    clock_t start = clock();

    for (int i = 0; i < 100000000; i++);
    clock_t end = clock();
    double waktu_eksekusi = (double)(end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(3) << waktu_eksekusi << " s" << endl;
    cout << "Tekan Sembarang Tombol Untuk Melanjutkan." << endl;

    return 0;
}
```
#### Output:
![Screenshot (493)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/68192cf5-9b7b-43e8-ad6c-13258b1edb32)


Penjelasan:

Pertama, program meminta pengguna untuk memasukkan jumlah kota dan kemudian menanyakan nama masing-masing kota. Selanjutnya, program meminta pengguna untuk memasukkan jarak antar pasang kota, menciptakan matriks ketetanggaan terbobot.

Setelah itu, program menampilkan matriks dalam tabel berformat dan menghitung waktu eksekusi menggunakan `fungsi clock()`, mensimulasikan penundaan untuk tujuan demonstrasi.

#### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
#include <iostream>
#include <queue>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // Konstruktor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void printChild(TNode *node) {
    if (node != NULL) {
        cout << "Anak Dari " << node->data << " : ";
        if (node->left != NULL) {
            cout << node->left->data << " ";
        }
        if (node->right != NULL) {
            cout << node->right->data << " ";
        }
        if (node->left == NULL && node->right == NULL) {
            cout << "Tidak Ada Anak.";
        }
        cout << endl;
    }
}

void printDescendant(TNode *node) {
    if (node != NULL) {
        if (node->left != NULL || node->right != NULL) {
            cout << "Turunan Dari " << node->data << " : ";
            queue<TNode*> q;
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
            while (!q.empty()) {
                TNode* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            cout << endl;
        } else {
            cout << "Turunan Dari " << node->data << " : Tidak Ada Turunan." << endl;
        }
    }
}

TNode* findNode(TNode* node, int value) {
    if (node == NULL) return NULL;
    if (node->data == value) return node;
    TNode* foundNode = findNode(node->left, value);
    if (foundNode == NULL) {
        foundNode = findNode(node->right, value);
    }
    return foundNode;
}

TNode* findParent(TNode* root, TNode* node) {
    if (root == NULL || root == node) return NULL;
    if (root->left == node || root->right == node) return root;
    TNode* foundNode = findParent(root->left, node);
    if (foundNode == NULL) {
        foundNode = findParent(root->right, node);
    }
    return foundNode;
}

void deleteNode(TNode* &root, int value) {
    TNode* node = findNode(root, value);
    if (node == NULL) {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    TNode* parent = findParent(root, node);
    
    // Node memiliki dua anak
    if (node->left != NULL && node->right != NULL) {
        TNode* successorParent = node;
        TNode* successor = node->right;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        node->data = successor->data;
        node = successor;
        parent = successorParent;
    }

    // Node memiliki nol atau satu anak
    TNode* child = (node->left != NULL) ? node->left : node->right;

    if (parent == NULL) {
        root = child;
    } else if (parent->left == node) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    delete node;
    cout << "Node berhasil dihapus!" << endl;
}

int main() {
    TNode *root = NULL;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Node" << endl;
        cout << "2. Hapus Node" << endl;
        cout << "3. Traversal Pre-Order" << endl;
        cout << "4. Traversal In-Order" << endl;
        cout << "5. Traversal Post-Order" << endl;
        cout << "6. Cetak Anak Node" << endl;
        cout << "7. Cetak Turunan Node" << endl;
        cout << "8. Cari Node" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilih Menu: ";
        
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan Nilai Node : ";
            int value;
            cin >> value;

            TNode *node = new TNode(value);

            if (root == NULL) {
                root = node;
            } else {
                int parentValue;
                cout << "Masukkan Node Induk Dari " << value << " : ";
                cin >> parentValue;
                TNode *parent = findNode(root, parentValue);
                if (parent == NULL) {
                    cout << "Node Induk Tidak Dapat Ditemukan!" << endl;
                    delete node;
                } else {
                    if (parent->left == NULL) {
                        parent->left = node;
                    } else if (parent->right == NULL) {
                        parent->right = node;
                    } else {
                        cout << "Node Induk Sudah Memiliki Dua Anak!" << endl;
                        delete node;
                    }
                }
            }

        } else if (pilihan == 2) {
            cout << "Masukkan Nilai Node yang Akan Dihapus : ";
            int value;
            cin >> value;
            deleteNode(root, value);

        } else if (pilihan == 3) {
            cout << "\nTraversal Pre-Order: ";
            preOrder(root);
            cout << endl;

        } else if (pilihan == 4) {
            cout << "\nTraversal In-Order: ";
            inOrder(root);
            cout << endl;

        } else if (pilihan == 5) {
            cout << "\nTraversal Post-Order: ";
            postOrder(root);
            cout << endl;

        } else if (pilihan == 6) {
            cout << "Masukkan Nilai Node: ";
            int value;
            cin >> value;
            printChild(findNode(root, value));

        } else if (pilihan == 7) {
            cout << "Masukkan Nilai Node: ";
            int value;
            cin >> value;
            printDescendant(findNode(root, value));

        } else if (pilihan == 8) {
            cout << "Masukkan Nilai Node: ";
            int value;
            cin >> value;
            TNode* node = findNode(root, value);
            if (node != NULL) {
                cout << "Node Ditemukan: " << node->data << endl;
            } else {
                cout << "Node Tidak Ditemukan" << endl;
            }

        } else if (pilihan == 9) {
            cout << "Keluar dari program." << endl;
            return 0;

        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
}
```
#### Output:
![Screenshot (494)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/49db1144-e72b-4424-bac6-e77b1a88aa01)

Penjelasan:

Program ini menggunakan struktur `TNode` untuk menyimpan nilai node dan pointer ke node anak kiri dan kanan. Fungsi `findNode` dan findParent membantu pencarian node dan node induknya. Fungsi `deleteNode` menangani penghapusan node dengan mempertimbangkan berbagai kasus seperti node dengan nol anak, satu anak, atau dua anak.

## Kesimpulan


Graph adalah struktur data non-linier yang terdiri dari simpul dan sisi, yang digunakan untuk merepresentasikan hubungan antar data dalam berbagai aplikasi kehidupan nyata seperti jejaring sosial. Berdasarkan karakteristiknya, graph dapat diklasifikasikan menjadi beberapa jenis seperti graf sederhana, graf tidak sederhana, graf berarah, graf tak-berarah, graf lengkap, graf kosong, dan graf berbobot. Penggunaan graph memiliki kelebihan dalam mengatur data, mengimplementasikan algoritma, dan menemukan jalur terpendek, namun juga memiliki kekurangan seperti kompleksitas memori yang besar dan penggunaan banyak pointer yang bisa rumit. Graph adalah alat yang efektif untuk memahami dan memvisualisasikan masalah yang kompleks.
## Referensi

[1] Joseph Teguh Santoso. *Struktur Data dan Algoritma*. Yayasan Primaagus Teknik. Semarang. 2021

[2] Dewi. *Pengertian, Jenis-jenis, Contoh, Kelebihan dan Kekurangan Struktur Data*. 2019. Available: https://dewikhrnnsa.blogspot.com/2019/02/pengertian-dan-jenis-jenis-struktur.html

[3] Fasilkom UI. *Dasar-Dasar Pemrograman 2*. Available: 
http://elearning.ai-innovation.id/pluginfile.php/77/mod_resource/content/1/DDP2_04_Jumat.pdf
