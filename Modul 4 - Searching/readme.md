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
int n = 10;: Ini adalah deklarasi variabel n dengan tipe data int dan nilai inisial 10. Variabel n akan digunakan untuk menyimpan jumlah elemen yang akan digunakan dalam array data.
int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};: Ini adalah deklarasi array data dengan tipe data int dan jumlah elemen yang sama dengan nilai n. Array data akan digunakan untuk menyimpan data yang akan dicari.
int cari = 10;: Ini adalah deklarasi variabel cari dengan tipe data int dan nilai inisial 10. Variabel cari akan digunakan untuk menyimpan data yang akan dicari.
bool ketemu = false;: Ini adalah deklarasi variabel ketemu dengan tipe data bool dan nilai inisial false. Variabel ketemu akan digunakan untuk menyimpan flag yang akan menunjukkan apakah data yang dicari ditemukan atau tidak.
int i;: Ini adalah deklarasi variabel i dengan tipe data int. Variabel i akan digunakan untuk menyimpan indeks array data yang sedang diperiksa.
for (i = 0; i < n; i++): Ini adalah perulangan for yang akan dijalankan sebanyak n kali. Perulangan ini akan mengulangi setiap elemen array data.
if(data[i] == cari): Ini adalah percabangan yang akan dieksekusi jika data yang ada pada indeks i sama dengan data yang dicari.
ketemu = true;: Ini adalah perintah untuk mengubah nilai variabel ketemu menjadi true jika data yang dicari ditemukan.
break;: Ini adalah perintah untuk menghentikan perulangan for jika data yang dicari ditemukan.
cout << "\t Program Sequential Search Sedeerhana\n" << endl;: Ini adalah perintah untuk menampilkan pesan "Program Sequential Search Sedeerhana" pada layar.
cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;: Ini adalah perintah untuk menampilkan data yang tersedia pada array data pada layar.
if (ketemu): Ini adalah percabangan yang akan dieksekusi jika nilai variabel ketemu adalah true.
cout << "\n angka "<< cari << " ditemukan pada indeks ke- " << i << endl;: Ini adalah perintah untuk menampilkan pesan "angka [cari] ditemukan pada indeks ke- [i]" pada layar.
else: Ini adalah percabangan yang akan dieksekusi jika nilai variabel ketemu adalah false.
cout << cari << " tidak dapat ditemukan pada data." << endl;: Ini adalah perintah untuk menampilkan pesan "cari tidak dapat ditemukan pada data." pada layar.
return 0;: Ini adalah perintah untuk mengakhiri program dengan nilai kembalian 0

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
Program ini adalah program C++ yang digunakan untuk mencari nilai maksimum dari suatu array. Ketika program dijalankan, user akan diminta untuk memasukkan panjang array. Setelah itu, user akan diminta untuk memasukkan elemen-elemen array. Kemudian, program akan menentukan nilai maksimum dari array tersebut dan lokasinya (index). Nilai maksimum dan lokasinya akan ditampilkan ke layar saat program selesai dieksekusi. Variabel yang digunakan dalam program ini antara lain `maks`, `a`, `i`dan `lokasi`. `maks` digunakan untuk menyimpan nilai maksimum, `a` digunakan untuk menyimpan panjang array, `i` digunakan sebagai indeks array, dan `lokasi` digunakan untuk menyimpan lokasi dari nilai maksimum. Perulangan `for` digunakan untuk melakukan iterasi pada setiap elemen di array, dan operasi penugasan digunakan untuk mengupdate nilai maksimum jika elemen tersebut lebih besar.

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
![Screenshot (350)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/f434bc15-cac1-414a-8940-601ea83ce2c2)

Penjelasan:

- `#include <iostream>` : Mendeklarasikan library input/output.
- `using namespace std;` : Menggunakan nama dari namespace standar.
- `int main()` : Memulai blok kode utama.
- `int genap[100], ganjil[100], jumlah_genap = 0, jumlah_ganjil = 0, a, i = 1;`: Mendeklarasikan beberapa variabel berupa integer yang akan digunakan untuk menyimpan data angka genap, ganjil, jumlah angka genap, jumlah angka ganjil dan panjang array.
- `cout << "Masukkan panjang array: ";`: Menampilkan output ke layar untuk meminta panjang array ke pengguna.
- `cin >> a;`: Meminta input pengguna untuk memasukkan panjang array.
- `int array[a];`: Mendeklarasikan array dengan panjang yang telah diinput pengguna.
- `cout << "Masukkan " << a << " angka:\n";`: Menampilkan output ke layar untuk meminta angka-angka ke pengguna.
- `for (i = 0; i < a; i++)`: Melakukan perulangan untuk meminta dan menyimpan angka-angka ke dalam array.
- `cout << "Array ke-" << (i) << ": ";`: Menampilkan output ke layar untuk meminta angka yang akan disimpan ke dalam array.
- `cin >> array[i];`: Meminta input pengguna untuk memasukkan angka dan menyimpan ke dalam array pada index ke-i.
- `cout << "Data Array: ";`: Menampilkan output ke layar untuk menampilkan data yang telah disimpan dalam array.
- `for (i = 0; i < a; i++)`: Melakukan perulangan untuk menampilkan data yang telah disimpan dalam array.
- `cout << array[i] << " ";`: Menampilkan data yang tersimpan pada index ke-i ke layar.
- `cout << "\n";`: Menampilkan output baris baru ke layar.
- `for (i = 0; i < a; i++)`: Melakukan perulangan untuk memisahkan angka genap dan ganjil.
- `if (array[i] % 2 == 0)`: Melakukan pengecekan apakah data pada index ke-i adalah bilangan genap atau ganjil.
- `genap[jumlah_genap] = array[i];`: Menyimpan data yang terdapat pada index ke-i ke dalam array genap jika data tersebut adalah bilangan genap.
- `jumlah_genap++;`: Menambahkan 1 ke variabel jumlah_genap setelah data genap diproses.
- `ganjil[jumlah_ganjil] = array[i];`: Menyimpan data yang terdapat pada index ke-i ke dalam array ganjil jika data tersebut adalah bilangan ganjil.
- `jumlah_ganjil++;`: Menambahkan 1 ke variabel jumlah_ganjil setelah data ganjil diproses.
- `cout << "\nNomor genap: ";`: Menampilkan output ke layar untuk menampilkan angka-angka genap.
- `for (i = 0; i < jumlah_genap; i++)`: Melakukan perulangan untuk menampilkan angka-angka genap.

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
![Screenshot (351)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/64e784f2-ab4c-40c7-bde5-1050b3e1b2f3)



Penjelasan:

- `#include <iostream>` : Mendeklarasikan library input/output.
- `using namespace std;` : Menggunakan nama dari namespace standar.
- `int main()` : Memulai blok kode utama.
- `int length, width, height;`: Mendeklarasikan tiga variabel `length`, `width`, dan `height` dengan tipe `int`.
- `cout << "Masukkan panjang array: ";`: Menampilkan tulisan "Masukkan panjang array: " ke layar.
- `cin >> length;`: Meminta input dari pengguna dan menyimpannya pada variabel `length`.
- `cout << "Masukkan lebar array: ";`: Menampilkan tulisan "Masukkan lebar array: " ke layar.
- `cin >> width;`: Meminta input dari pengguna dan menyimpannya pada variabel `width`.
- `cout << "Masukkan tinggi array: ";`: Menampilkan tulisan "Masukkan tinggi array: " ke layar
- `cin >> height;`: Meminta input dari pengguna dan menyimpannya pada variabel `height`
- `int array[length][width][height];`: Mendeklarasikan dan menginisialisasi array 3 dimensi dengan nama array.
- `for (int x = 0; x < length; x++)`: Memulai perulangan `for` dengan nama variabel `x` dan batas `length`.
- `for (int y = 0; y < width; y++)`: Memulai perulangan `for` dengan nama variabel `y` dan batas `width`.
- `for (int z = 0; z < height; z++)`: Memulai perulangan `for` dengan nama variabel `z` dan batas `height`.
`cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";`: Menampilkan tulisan "Input Array[x][y][z] = " ke layar.
- `cin >> array[x][y][z];`: Meminta input dari pengguna dan menyimpannya pada elemen array array[x][y][z].
- `cout << endl;`: Menampilkan baris baru ke layar
for (int x = 0; x < length; x++): Memulai perulangan `for` dengan nama variabel `x` dan batas `length`.
- `for (int y = 0; y < width; y++)`: Memulai perulangan `for` dengan nama variabel `y` dan batas `width`.
- `for (int z = 0; z < height; z++)`: Memulai perulangan `for` dengan nama variabel `z` dan batas `height`.
- `cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << array[x][y][z] << endl;`: Menampilkan tulisan "Data Array[x][y][z] = " dan nilai dari elemen array ke layar.
- `for (int x = 0; x < length; x++)`: Memulai perulangan `for` dengan nama variabel `x` dan batas `length`.
`for (int y = 0; y < width; y++)`: Memulai perulangan `for` dengan nama variabel `y` dan batas `width`.
`for (int z = 0; z < height; z++)`: Memulai perulangan `for` dengan nama variabel `z` dan batas `height`.
`cout << array[x][y][z] << " ";`: Menampilkan nilai dari elemen array.

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
![Screenshot (353)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/548b8563-2182-4f4b-bd7b-5077cda07a71)

Penjelasan:

- `#include <iostream>` : Mendeklarasikan library input/output.
- `using namespace std;` : Menggunakan nama dari namespace standar.
- `int main()` : Memulai blok kode utama.
- `int maks, a, i = 1, lokasi;` : Mendeklarasikan variabel yang digunakan.
- `cout << "Masukkan Panjang array: ";` : Menampilkan text "Masukkan Panjang array: ".
- `cin >> a;` : Meminta masukan panjang array dan disimpan ke variabel `a`.
- `int array[a];` : Mendeklarasikan array dengan panjang `a`.
- `cout << "Masukkan " << a << " angka\n";` : Menampilkan text "Masukkan " dan panjang array.
- `for (i = 0; i < a; i++)` : Perulangan untuk input elemen array.
- `cout << "Array ke-" << (i) << ": ";` : Menampilkan text "Array ke-" dan indeks
- `cin >> array[i];` : Meminta masukan nilai elemen array.
- `maks = array [0];` : Menginisialisasi variabel maksimum dengan elemen pertama array.
- `lokasi = 0;` : Menginisialisasi variabel lokasi.
- `for (i = 0; i < a; i++)` : Perulangan untuk mencari nilai maksimum.
- `if (array[i] > maks)` : Membandingkan nilai elemen array dengan nilai maksimum.
- `maks = array[i];` : Menetapkan nilai maksimum.
- `lokasi = i;` : Menetapkan lokasi nilai maksimum.
- `int min = array[0];` : Menginisialisasi variabel minimum dengan elemen pertama array.
- `for (i = 0; i < a; i++)` : Perulangan untuk mencari nilai minimum.
- `if (array[i] < min)` : Membandingkan nilai elemen array dengan nilai minimum.
- `min = array[i];` : Menetapkan nilai minimum
- `lokasi = i;` : Menetapkan lokasi nilai minimum.
- `double sum = 0;` : Menginisialisasi variabel sum
- `for (i = 0; i < a; i++)` : Perulangan untuk menjumlahkan semua elemen array.
- `sum += array[i];` : Menjumlahkan nilai array.
- `double average = sum / a;` : Menghitung rata-rata.
- `cout << " Rata-rata nilai adalah " << average << endl;` : Menampilkan rata-rata.


## Kesimpulan
Dalam pemrograman, array adalah struktur data yang memungkinkan penyimpanan kumpulan nilai data yang sama, diakses melalui indeks. Ada tiga jenis array: satu dimensi, dua dimensi, dan multidimensi. Array memiliki kelebihan seperti kemudahan akses acak dan efisiensi penyimpanan nilai independen. Namun, terdapat kekurangan seperti harus bertipe homogen dan sulit mengubah ukuran array statis pada waktu eksekusi. Meskipun demikian, array tetap menjadi salah satu struktur data yang efisien dalam banyak kasus pemrograman karena kemampuannya menyimpan dan mengakses data secara terstruktur.

## Referensi

[1] Syaiful Anam, Indah Yanti, Zuraidah Fitriah, Ummu Habibah. *Cara Mudah Belajar Bahasa Pemrograman C++*. Malang: Universitas Brawijaya Press. 2021

[2] Rina Firliana, Patmi Kasih. *Algoritma & Pemrograman C++*. Nganjuk: Adjie Media Nusantara. 2018

[3] M. Aldi Pratama. *STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++*. 29 Maret 2020. [online]. Available: https://osf.io/preprints/osf/vyech

[4] Vivian Siahaan, Rismon Hasiholan Sianipar. *BUKU PINTAR Pemrograman C++ Untuk Pelajar dan Mahasiswa*. 15 Mar 2020. Sumatra Utara: Balige Publishing.

[5] Angan Prawista. *Array pada C++*. Diakses pada 25 Maret 2024. [online]. Available: https://wistaprawista.wordpress.com/materi/algoritma-dan-struktur-data/array-pada-c/
