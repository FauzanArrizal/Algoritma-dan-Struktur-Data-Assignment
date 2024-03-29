# <h1 align="center">Laporan Praktikum Modul 3 Sorting</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Sorting
Sorting adalah.. [1].

#### 2. Jenis Sorting Berdasar Data Terurutnya
2.1. Ascending...

2.2. Discending...

#### 3. Macam-macam Algoritma Sorting
3.1. Insertion Sort...

3.2. Bubble Sort...

3.3. Selection Sort...

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
- `using namespace std;` : Menggunakan nama dari namespace standar.


## Kesimpulan
...

## Referensi

[1] Syaiful Anam, Indah Yanti, Zuraidah Fitriah, Ummu Habibah. *Cara Mudah Belajar Bahasa Pemrograman C++*. Malang: Universitas Brawijaya Press. 2021

[2] Rina Firliana, Patmi Kasih. *Algoritma & Pemrograman C++*. Nganjuk: Adjie Media Nusantara. 2018

[3] M. Aldi Pratama. *STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++*. 29 Maret 2020. [online]. Available: https://osf.io/preprints/osf/vyech

[4] Vivian Siahaan, Rismon Hasiholan Sianipar. *BUKU PINTAR Pemrograman C++ Untuk Pelajar dan Mahasiswa*. 15 Mar 2020. Sumatra Utara: Balige Publishing.

[5] Angan Prawista. *Array pada C++*. Diakses pada 25 Maret 2024. [online]. Available: https://wistaprawista.wordpress.com/materi/algoritma-dan-struktur-data/array-pada-c/
