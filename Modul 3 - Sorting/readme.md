# <h1 align="center">Laporan Praktikum Modul 3 Sorting</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Sorting
Sorting merupakan proses menyusun elemen–elemen dari masukan awal acak  menjadi tertata dengan urutan tertentu [1].

#### 2. Jenis Sorting Berdasar Data Terurutnya
2.1. Ascending Sort merupakan pengurutan dari data yang terkecil ke data terbesar, singkatnya urut naik. 
Contoh: "1, 2, 3", "A, B, C" [2].

2.2. Descending Sort merupakan pengurutan dari data yang terbesar ke data terkecil, singkatnya urut turun. 
Contoh: "3, 2, 1", "C, B, A" [2].

#### 3. Macam-macam Algoritma Sorting
3.1. Insertion Sort adalah algoritma pengurutan yang bekerja dengan cara yang mirip dengan bermain kartu dengan tangan. Tidak seperti algoritma sort bubble atau algoritma sort lainnya, algoritma ini sangat sederhana dan mudah diperaktekan. Jika Anda memiliki banyak data yang diurutkan, algoritma ini sangat cocok untuk digunakan [4].

3.2. Bubble Sort adalah algoritma yang didasarkan pada gelembung sabun yang terapung di atas air. Ini terjadi karena berat jenis gelembung sabun lebih ringan daripada berat jenis air. Apabila larik terurut diinginkan naik, elemen larik yang paling kecil diapungkan ke atas melalui proses pertukaran, atau arah perbandingan dilakukan dari belakang [3].
 

3.3. Selection Sort adalah algoritma pengurutan sederhana digunakan untuk mencari elemen terkecil atau terbesar dalam array dan menukar posisinya dengan elemen pertama. Kemudian, algoritma ini mencari elemen terkecil atau terbesar berikutnya dalam sisa array yang belum terurut dan menukar posisinya dengan elemen kedua. Sampai seluruh array terurut, prosedur ini diulangi berulang kali [5].

## Guided 


### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>

using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of it
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};
    
    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Program ...


### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>

using namespace std;

void insertion_sort(char arr[],  int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;
        while ((j > 0) && (arr[j] < arr[j - 1])) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }// end of while loop
    }// end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 6;
    char a [length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
Program...

## Unguided 

#### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!

```C++
#include <iostream>
using namespace std;

// Fungsi selection sort mengurutkan array float dari besar ke kecil
void selectionSort(float arr[], int n) {
  for (int i = 0; i < n-1; i++) {
    int maxIndex = i;
    for (int j = i+1; j < n; j++) {
      if (arr[j] > arr[maxIndex]) {
        maxIndex = j;
      }
    }
    swap(arr[maxIndex], arr[i]);
  }
}

void cetak_array(float a[], int length) {
  for(int i=0; i<length; i++) {
    cout << a[i] << "    ";
  }
  cout << endl;
}

int main() {
  // Array IPS mahasiswa
  float arr[] = {3.8, 2.9, 3.3, 4.0, 2.4};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "IPS mahasiswa sebelum diurutkan: ";
  cetak_array(arr, n);
  selectionSort(arr, n);
  cout << "IPS mahasiswa setelah diurutkan: ";
  cetak_array(arr, n);
  return 0;
}
```
#### Output:
![Screenshot (356)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/465d5f25-8412-4ce3-ab76-5084d102044c)

Penjelasan:

- `#include <iostream>` : Mendeklarasikan library input/output.
- `using namespace std;` : Menggunakan nama dari namespace standar.
- `void selectionSort(float arr[], int n):` Fungsi selectionSort yang menerima dua parameter, yaitu array float `arr` dan panjang array `n`. Fungsi ini akan mengurutkan array `arr` dari besar ke kecil.
- `void cetak_array(float a[], int length):` Fungsi cetak_array yang menerima dua parameter, yaitu array float `a` dan panjang array `length`. Fungsi ini akan mencetak isi dari array `a` dengan panjang `length`.
- `int main():` Fungsi utama yang akan dieksekusi ketika program dijalankan.
- `float arr[] = {3.8, 2.9, 3.3, 4.0, 2.4};`: Membuat array float `arr` dengan panjang 5 elemen.
- `int n = sizeof(arr)/sizeof(arr[0]);`: Menghitung panjang array arr.
- `cout << "IPS mahasiswa sebelum diurutkan: ";:` Menampilkan pesan "IPS mahasiswa sebelum diurutkan: " ke layar.
- `cetak_array(arr, n);`: Menampilkan isi dari array arr sebelum diurutkan.
- `selectionSort(arr, n);`: Memanggil fungsi selectionSort untuk mengurutkan array arr dari besar ke kecil.
- `cout << "IPS mahasiswa setelah diurutkan: ";`: Menampilkan pesan "IPS mahasiswa setelah diurutkan: " ke layar.
- `cetak\_array(arr, n);`: Menampilkan isi dari array arr setelah diurutkan.
- `return 0;`: Mengembalikan nilai 0 ke sistem operasi.

#### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
#include <iostream>
#include <string>

using namespace std;

// Fungsi bubble sort mengurutkan array string dari kecil ke besar
void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void cetak_array(string a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "   ";
    }
    cout << endl;
}

int main() {
    // Array nama warga
    string arr[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Nama-nama warga sebelum diurutkan: ";
    cetak_array(arr, n);
    bubbleSort(arr, n);
    cout << "Nama-nama warga setelah diurutkan: ";
    cetak_array(arr, n);
    return 0;
}
```
Output:
![Screenshot (357)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/b070b66c-3f54-4cdd-94df-7b63813f8a94)



Penjelasan:

- `#include <iostream>` : Mendeklarasikan library input/output.
- `using namespace std;` : Menggunakan nama dari namespace standar.
- `#include <iostream>` : Mendeklarasikan library input/output.
- `#include <string>` : Mendeklarasikan library string.
- `using namespace std;` : Menggunakan nama dari namespace standar.
- `string arr[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};`: Mendeklarasikan array of strings arr dengan 10 elemen.
- `int n = sizeof(arr)/sizeof(arr[0]);` : Menghitung panjang array arr.
- `cout << "Nama-nama warga sebelum diurutkan: ";`: Menampilkan pesan "Nama-nama warga sebelum diurutkan: " ke layar.
- `cetak_array(arr, n);` : Menampilkan isi dari array arr sebelum diurutkan.
- `bubbleSort(arr, n);`: Memanggil fungsi bubbleSort untuk mengurutkan array arr dari kecil ke besar.
- `cout << "Nama-nama warga setelah diurutkan: ";`: Menampilkan pesan "Nama-nama warga setelah diurutkan: " ke layar.
- `cetak_array(arr, n);`: Menampilkan isi dari array arr setelah diurutkan.
- `return 0;`: Mengembalikan nilai 0 ke sistem operasi.

#### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

```C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Masukkan bilangan <n>: ";
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Karakter ke-" << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "\nUrutan karakter sebelum sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "    ";
    }
    sort(arr.begin(), arr.end());
    cout << "\nUrutan karakter setelah ascending sort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "    ";
    }
    sort(arr.begin(), arr.end(), greater<char>());
    cout << "\nUrutan karakter setelah descending sort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "    ";
    }
    return 0;
}
```
#### Output:
![Screenshot (358)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/7e04bf43-d907-482b-b8f8-3265baae386d)

Penjelasan:

- `#include <iostream>` : Mendeklarasikan library input/output.
- `#include <algorithm>` : Mendeklarasikan library untuk algoritma umum.
- `#include <vector>` : Mendeklarasikan library untuk container dinamis.
- `using namespace std;` : Menggunakan nama dari namespace standar.
- `int n;` : Mendeklarasikan variabel `n` untuk menyimpan bilangan yang akan dimasukkan user.
- `cin >> n;` : Meminta user memasukkan bilangan `n`.
- `vector<char> arr(n);` : Mendeklarasikan vektor `arr` dengan kapasitas `n`.
- `for (int i = 0; i < n; i++)`: Looping untuk meminta user memasukkan `n` karakter.
- `cout << "Urutan karakter sebelum sorting:\n";` : Menampilkan pesan "Urutan karakter sebelum sorting:".
- `for (int i = 0; i < n; i++)` : Looping untuk menampilkan urutan karakter sebelum diurutkan.
- `sort(arr.begin(), arr.end());` : Mengurutkan elemen vektor `arr` dari elemen terkecil ke terbesar.
- `cout << "\nUrutan karakter setelah ascending sort:\n";` : Menampilkan pesan "Urutan karakter setelah ascending sort:".
- `for (int i = 0; i < n; i++)` : Looping untuk menampilkan urutan karakter setelah diurutkan secara ascending.
- `sort(arr.begin(), arr.end(), greater<char>());` : Mengurutkan elemen vektor `arr` dari elemen terbesar ke terkecil.
- `cout << "\nUrutan karakter setelah descending sort:\n";` : Menampilkan pesan "Urutan karakter setelah descending sort:".
- `for (int i = 0; i < n; i++)` : Looping untuk menampilkan urutan karakter setelah diurutkan secara descending.
`return 0;` : Mengembalikan nilai 0 ke sistem operasi.


## Kesimpulan
Dapat disimpulkan bahwa sorting adalah proses pengaturan elemen dalam suatu himpunan data dari keadaan acak menjadi terurut sesuai aturan tertentu. Terdapat dua jenis utama sorting, yaitu Ascending Sort (dari kecil ke besar) dan Descending Sort (dari besar ke kecil).

Selain itu, terdapat beberapa algoritma sorting yang umum digunakan seperti Insertion Sort, Bubble Sort, dan Selection Sort. Insertion Sort merupakan algoritma sederhana yang cocok untuk data dalam jumlah sedang. Namun, dari berbagai algoritma tersebut, Insertion Sort dianggap relevan karena kepraktisannya dalam implementasi.

Dengan demikian, walaupun terdapat beragam algoritma sorting, pemilihan Insertion Sort sebagai algoritma yang paling relevan dapat disesuaikan dengan kebutuhan spesifik pengurutan data, terutama dalam konteks kemudahan penerapan dan kinerja yang efisien.

## Referensi

[1] Nasution RA. *Sorting Menggunakan C++ Beserta Contohnya*. Diakses pada 30 Maret 2024. [online]. Available: https://www.kompasiana.com/rezaan2434/62bad3e20428246cf42d6482/sorting-menggunakan-c-beserta-contohnya.

[2] Rina Firliana, Patmi Kasih. *Algoritma & Pemrograman C++*. Nganjuk: Adjie Media Nusantara. 2018

[3] Arifin RW, Setiyadi D. *Algoritma Metode Pengurutan Bubble Sort dan Quick Sort Dalam Bahasa Pemrograman C++*. 2020

[4] Adinata. *Contoh Program Algoritma Insertion Sort C++ beserta penjelasan*. Diakses pada 30 Maret 2024. [online]. Available: https://midteknologi.com/blog/algoritma-insertion-sort/

[5] Laurentius Joandanu. *Selection Sort di C++*. Diakses pada 30 Maret 2024. [online]. Available: https://medium.com/@danuljoan/selection-sort-di-c-7de265eb23a#:~:text=Selection%20Sort%20adalah%20algoritma%20pengurutan,menukar%20posisinya%20dengan%20elemen%20pertama.