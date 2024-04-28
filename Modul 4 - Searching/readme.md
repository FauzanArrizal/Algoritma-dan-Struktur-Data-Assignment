# <h1 align="center">Laporan Praktikum Modul 4 Searching</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Searching
Searching adalah suatu algoritma yang digunakan untuk mencari data yang sesuai dengan kriteria yang diinginkan. Algoritma Searching terdiri atas dua jenis utama, yaitu Linear Searching dan Binary Searching.[1].

#### 2. Jenis Searching
##### - Sequential Search.

Sequential Search(pencarian    berurutan) dikenal juga sebagai pencarian linier. Sequential Searchmerupakan algoritma pencarian paling dasar dan paling sederhana yang bekerja menggunakan pendekatan bruteforce, mencoba segala   kemungkinan yang ada hingga target   yang diinginkan ditemukan. Sebagai contoh, mencari nilai 36 dari data array{12, 7, 30, 28, 2, 19, 36, 21, 16, 9}. Sequential Search dimulai dengan membandingkan/mencocokkan 36 dengan elemen pertama/`index[0]` yaitu 12,  karena 12 tidak sesuai dengan kriteria pencarian (12!= 36)  maka dilanjutkan dengan membandingkan 36 dengan elemen berikutnya hingga ditemukan elemen  yang cocok, yaitu pada `index[6]` dimana 36 == 36 [2].


##### - Binary Search

Algoritma Binary Searchbekerja dengan  menggunakan pendekatan devide and  conquer pada data array yang sudah  terurut (sorted), artinya algoritma Binary Search diawali dengan   mengurutkan (sorting) array terlebih  dahulu sebelum melakukan proses  pencarian (Goodrich et al, 2014).Setelah data array terurut proses   pencarian dimulai dengan perulangan  pertama untuk mencari elemen yang  posisinya berada di tengah array, kemudian membandingkan elemen tengah tersebut dengan kunci pencarian, jika  kunci pencarian lebih besar dari  elemen tengah, maka abaikan semua  elemen array yang berada di posisi  kiri lanjutkan perulangan kedua dengan mencari  elemen  tengah  pada arraysisi kanan saja dan dibandingkan lagi  dengan kunci pencarian. Namun apabila  kunci pencarian lebih kecil dari  elemen tengah maka abaikan semua  elemen array di posisi kanan dan  lanjutkan perulangan kedua dengan  mencari elemen tengah pada array sisi kiri lalu bandingkan dengan kunci pencarian. langkah-langkah ini dilakukan berulang sampai dengan ditemukan elemen tengah yang sama   dengan kunci pencarian atau elemen   telah habis dibandingkan [2]. 


## Guided 


### 1. Sequential Search

```C++
#include <iostream>

using namespace std;

int main ()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential search
    for (i = 0; i < n; i++) 
    {
        if(data[i] == cari) 
        {
            ketemu = true;
            break;
        }
    }


    cout << "\t Program Sequential Search Sedeerhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu)
    {
        cout << "\n angka "<< cari << " ditemukan pada indeks ke- " << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```

Output:
![Screenshot (373)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/fdb90d93-d153-4488-bdb5-4927a682ee5e)

Penjelasan:

- `int n = 10;`: deklarasi variabel n dengan tipe data int dan nilai inisial 10. Variabel n akan digunakan untuk menyimpan jumlah elemen yang akan digunakan dalam array data.
- `int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};`: deklarasi array data dengan tipe data int dan jumlah elemen yang sama dengan nilai n. Array data akan digunakan untuk menyimpan data yang akan dicari.
- `int cari = 10;`: variabel cari dengan tipe data int dan nilai inisial 10. Variabel cari akan digunakan untuk menyimpan data yang akan dicari.
- `bool ketemu = false;`: variabel ketemu dengan tipe data bool dan nilai inisial false. Variabel ketemu akan digunakan untuk menyimpan flag yang akan menunjukkan apakah data yang dicari ditemukan atau tidak.
- `int i;`: variabel i dengan tipe data int. Variabel i akan digunakan untuk menyimpan indeks array data yang sedang diperiksa.
- `for (i = 0; i < n; i++)`: perulangan for yang akan dijalankan sebanyak n kali. Perulangan ini akan mengulangi setiap elemen array data.
- `if(data[i] == cari)`: percabangan yang akan dieksekusi jika data yang ada pada indeks i sama dengan data yang dicari.
- `ketemu = true;`:  untuk mengubah nilai variabel ketemu menjadi true jika data yang dicari ditemukan.
- `break;`:  untuk menghentikan perulangan for jika data yang dicari ditemukan.
- `cout << "\t Program Sequential Search Sedeerhana\n" << endl;`:  untuk menampilkan pesan "Program Sequential Search Sedeerhana" pada layar.
- `cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;`: untuk menampilkan data yang tersedia pada array data pada layar.
- `if (ketemu)`:  percabangan yang akan dieksekusi jika nilai variabel ketemu adalah true.
- `cout << "\n angka "<< cari << " ditemukan pada indeks ke- " << i << endl;`: untuk menampilkan pesan "angka [cari] ditemukan pada indeks ke- [i]" pada layar.
- `else`: percabangan yang akan dieksekusi jika nilai variabel ketemu adalah false.
- `cout << cari << " tidak dapat ditemukan pada data." << endl;`: untuk menampilkan pesan "cari tidak dapat ditemukan pada data." pada layar.
- `return 0;`: untuk mengakhiri program dengan nilai kembalian 0

### 2. Binary Search

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int cari;

void selection_sort(int data[], int length) {
    int temp, min, i, j; 
    for(i = 0; i < length; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch(int data[], int length) {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = length - 1;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if(b_flag == 1)
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    else
        cout << "\n Data tidak ditemukan\n";
}

int main() {
    int data[7] = {1, 8, 2, 5, 4, 9, 7};
    int length = sizeof(data) / sizeof(data[0]);

    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    // Tampilkan data awal
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    cout << "\n Masukkan data yang ingin anda cari : ";
    cin >> cari;

    cout << "\n Data diurutkan : ";
    // Urutkan data dengan selection sort
    selection_sort(data, length);

    // Tampilkan data setelah diurutkan 
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    binarysearch(data, length);
    _getche();
    return EXIT_SUCCESS;
}
```
Output:
![Screenshot (374)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/852b6541-5891-48aa-a308-bcd2a078b78f)

Penjelasan:

Program ini menggunakan algoritma selection sort dan binary search untuk mengurutkan dan mencari `data` dalam array data. Pengguna dapat memasukkan data yang ingin dicari, dan program akan menampilkan data yang telah diurutkan dan menunjukkan indeks dari data yang dicari.


## Unguided 

#### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>

using namespace std;

int binarysearch(const string& str, char cariChar) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == cariChar) {
            return i;
        }
    }
    return -1;
}

int main() {
    string str;
    char cariChar;
    int indeks;

    cout << "Masukkan kalimat: ";
    getline(cin, str);

    if (str.empty()) {
        cout << "Kalimat kosong. Stop Program";
        return 1;
    }

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> cariChar;

    indeks = binarysearch(str, cariChar);

    if (indeks != -1) {
        cout << "Huruf '" << cariChar << "' ditemukan pada indeks ke-" << indeks + 1 << "." << endl;
    } 
    else {
        cout << "Huruf '" << cariChar << "' tidak ditemukan pada kalimat." << endl;
    }
    return 0;
}
```
#### Output:
![Screenshot (375)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/a676217b-b64a-42e0-b055-306f667c0e1f)


Penjelasan:

- `int main()` : deklarasi fungsi utama dari program C++.
- `string str;, char cariChar;, dan int indeks;`: variabel lokal dalam fungsi main(). Variabel str adalah string yang akan digunakan untuk menyimpan input dari pengguna. Variabel cariChar adalah karakter yang akan dicari dalam string. Variabel indeks akan menampung hasil pencarian karakter dalam string.
- `cout << "Masukkan kalimat: ";`: pesan yang akan dicetak ke layar, meminta pengguna untuk memasukkan kalimat.
- `getline(cin, str);`: cara untuk membaca satu baris teks dari input pengguna menggunakan getline(). Teks yang dimasukkan akan disimpan dalam variabel str.
- `if (str.empty())`: percabangan kondisional. Memeriksa apakah string yang dimasukkan oleh pengguna kosong atau tidak menggunakan metode empty() dari objek string str.
- `cout << "Kalimat kosong. Stop Program";`: Jika string kosong, pesan ini akan dicetak ke layar.
- `return 1;`: mengembalikan nilai 1 dari fungsi main(), yang menandakan bahwa program berhenti karena ada kesalahan.
- `cout << "Masukkan huruf yang ingin dicari: ";`: pesan yang meminta user untuk memasukkan karakter yang ingin dicari dalam kalimat.
- `cin >> cariChar;`: cara untuk membaca satu karakter dari input pengguna menggunakan cin. Karakter yang dimasukkan akan disimpan dalam variabel cariChar.
- `indeks = binarysearch(str, cariChar);`: pemanggilan fungsi binarysearch dengan argumen str (kalimat yang dimasukkan oleh pengguna) dan cariChar (karakter yang ingin dicari dalam kalimat).
- `return 0;`: mengembalikan nilai 0 dari fungsi main(), menandakan bahwa program berakhir dengan sukses.

#### 2. Buatlah sebuah program yang dapat menghitung banyaknya hurufvocal dalam sebuah kalimat!

```C++
#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

int countVowels(const string& sentence, unordered_set<char>& vowelsFound) {
    int count = 0;
    for (char ch : sentence) {
        char lowerCh = tolower(ch);
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            count++;
            vowelsFound.insert(ch);
        }
    }
    return count;
}

int main() {
    string sentence;
    unordered_set<char> vowelsFound;

    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    int vowelCount = countVowels(sentence, vowelsFound);

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << vowelCount << endl;

    cout << "Huruf vokal yang ditemukan pada kalimat: ";
    for (char ch : vowelsFound) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}
```
Output:
![Screenshot (377)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/c0ab6c18-d3eb-44f2-9eac-f00287887731)

Penjelasan:

- `#include <iostream>`: Menggunakan
library iostream untuk operasi input-output.
- `#include <string>`: Menggunakan library string untuk bekerja dengan tipe data string.
- `#include <cctype>`: Menggunakan library cctype untuk operasi terkait karakter.
- `#include <unordered_set>`: Menggunakan library unordered_set untuk menggunakan struktur data set yang tidak berurutan.
- `using namespace std;`: Menggunakan namespace std untuk mempermudah penggunaan elemen dari namespace tersebut.
- `int countVowels(const string& sentence, unordered_set<char>& vowelsFound) {`: Mendefinisikan fungsi countVowels yang menghitung jumlah huruf vokal dalam sebuah kalimat dan menyimpan huruf vokal yang ditemukan dalam sebuah set.
- `int main() {`: Mendefinisikan fungsi main() sebagai titik masuk utama untuk program.
- `string sentence;`: Deklarasi variabel sentence untuk menyimpan kalimat yang dimasukkan oleh pengguna.
- `unordered_set<char> vowelsFound;`: Deklarasi unordered_set vowelsFound untuk menyimpan huruf vokal yang ditemukan dalam kalimat.
- `cout << "Masukkan kalimat: ";`: Menampilkan pesan meminta pengguna untuk memasukkan kalimat.
- `getline(cin, sentence);`: Membaca kalimat yang dimasukkan oleh pengguna dan menyimpannya dalam variabel sentence.
- `int vowelCount = countVowels(sentence, vowelsFound);`: Memanggil fungsi countVowels untuk menghitung jumlah huruf vokal dalam kalimat.
- `cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << vowelCount << endl;`: Menampilkan jumlah huruf vokal yang ditemukan dalam kalimat.
- `cout << "Huruf vokal yang ditemukan pada kalimat: ";`: Menampilkan pesan sebelum menampilkan huruf vokal yang ditemukan.
- `for (char ch : vowelsFound) { cout << ch << " "; }`: Melakukan iterasi melalui set vowelsFound dan menampilkan setiap huruf vokal yang ditemukan.
- `return 0;`: Mengembalikan nilai 0, menandakan bahwa program berakhir dengan sukses.

#### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>
#include <vector>

using namespace std;

int sequentialSearch(const vector<int>& data, int key) {
    int count = 0;
    for (int num : data) {
        if (num == key) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int key = 4;

    int count = sequentialSearch(data, key);

    cout << "Banyaknya angka " << key << " pada data adalah: " << count << endl;

    return 0;
}
```
#### Output:
![Screenshot (378)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/dc716b4c-3cda-41ec-b0d8-f7f141fad598)

Penjelasan:

- `#include <iostream>`: Menggunakan library iostream untuk operasi input-output.
- `#include <vector>`: Menggunakan library vector untuk menggunakan struktur data vector.
- `using namespace std;`: Menggunakan namespace std untuk mempermudah penggunaan elemen dari namespace tersebut.
- `int sequentialSearch(const vector<int>& data, int key) {`: Mendefinisikan fungsi sequentialSearch yang mengambil vector data dan integer key, dan mengembalikan jumlah kemunculan key dalam vector data.
- `int count = 0;`: Mendeklarasikan variabel count untuk menghitung jumlah kemunculan key dalam vector.
- `for (int num : data) {`: Melakukan iterasi melalui setiap elemen dalam vector data.
- `if (num == key) { count++; }`: Memeriksa apakah elemen saat ini sama dengan key, jika ya, menambahkan nilai count.
- `return count;`: Mengembalikan nilai count yang merupakan jumlah kemunculan key dalam vector data.
- `int main() {`: Mendefinisikan fungsi main() sebagai titik masuk utama untuk program.
- `vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};`: Mendefinisikan vector data yang berisi sejumlah nilai.
- `int key = 4;`: Mendeklarasikan nilai key yang ingin dicari dalam vector.
int count = sequentialSearch(data, key);: Memanggil fungsi sequentialSearch untuk mencari jumlah kemunculan key dalam vector data.
- `cout << "Banyaknya angka " << key << " pada data adalah: " << count << endl;`: Menampilkan jumlah kemunculan key dalam vector data.
- `return 0;`: Mengembalikan nilai 0, menandakan bahwa program berakhir dengan sukses.

## Kesimpulan
Searching merupakan proses pencarian data yang sesuai dengan kriteria yang ditentukan. Dua jenis utama dari algoritma searching adalah Sequential Search dan Binary Search. Sequential Search melakukan pencarian secara berurutan, sementara Binary Search menggunakan pendekatan divide and conquer pada data yang sudah terurut. Sequential Search cocok untuk data yang tidak terurut, sementara Binary Search lebih efisien untuk data yang terurut karena memanfaatkan sifat data yang terurut untuk proses pencarian yang lebih cepat.

## Referensi

[1] Wanra Tarigan. *Algoritma Pemrograman dan Struktur Data*. Jawa Tengah: Aeureka Media Aksara. 2022

[2] Meidyan Permata Putri, Guntoro Barovih, Rezania Agramanisti Azdy, Yuniansyah, Andri Saputra, Yesi Sriyeni, Arsia Rini, Fadhila Tangguh Admojo.*Algoritma dan Struktur Data*. Bandung: Widina Bhakti Persada. 2022
