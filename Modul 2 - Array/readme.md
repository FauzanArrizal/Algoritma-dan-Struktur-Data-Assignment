# <h1 align="center">Laporan Praktikum Modul 2 Array</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Pengertian array
Array adalah sekumpulan nilai-nilai data yang sama, yang terurut dan dikelompokkan berdasarkan nama yang sama. Elemen-elemen array disebut dengan subscript atau indeks. Pendeklarasian array akan membuat kompiler mengalokasikan memori yang cukup untuk menampung semua elemen sesuai dengan yang dideklarasikan. Array dibedakan menjadi tiga macam: array satu dimensi, array dua dimensi, dan array berdimensi banyak.[1].

#### 2. Array menurut dimensinya
2.1. Array satu dimensi. Setiap elemen array dapat diakses melalui index Index array secara default dimulai dari 0. Deklarasi array : `Tipe_nama array_array[ukuran]`[2].

2.2. Array dua dimensi. Array dua dimensi merupakan array yang terdiri dari m buah baris dan n buah buah kolom bentuknya dapat berupa matriks atau tabel. Deklarasi array : `Tipe_nama array_array [baris][kolom]`[2].

2.3. Array multidimensi merupakan array yang mempunyai ukuran lebih dari dua. Bentuk pendeklarasian array multidimensi sama saja dengan deklarasi array dimensi satu maupun dimensi dua. Deklarasi array : `Tipe_nama array_array [ukuran 1][ukuran 2] . . . [ukuran N]`[2].

#### 3. Perbedaan array dengan tipe data lain
Array dapat memiliki banyak nilai, sedangkan tipe data lain hanya terhubung dengan satu nilai saja. Array dapat digunakan untuk menyimpan beberapa nilai tipe data lain (char, int, float, double, long, dll), yang sama dengan satu nama saja. Selain itu, array dapat berupa satu dimensi atau lebih, sedangkan tipe data lain hanya berupa satu dimensi[5].

#### 4. Kelebihan dan Kekurangan Array
##### Kelebihan:
- Array sangat cocok untuk pengaksesan acak. Sembarang di array dapat diacu secara langsung tanpa melaui elemen-elemen lain.
- Jika berada di suatu lokasi, maka sangat mudah menelusuri ke elemen-elemen tetangga, baik elemen pendahulu maupun elemen penerus.
- Jika elemen array adalah nilai independen dan seluruhnya harus terjaga, maka penggunaan penyimpanannya sangat efisien[4].

##### Kekurangan:
- Array harus bertipe homogen, tidak dapat mempunyai array yang berbeda-beda tipe dalam satu array.
- Banyak bahasa pemrograman yang menerapkan array statik yang sulit dirubah ukurannya pada waktu eksekusi. Bila penambahan dan pengurangan terjadi terus menerus, maka representasi statis tidak efisien dalam penggunaan memori[4]. 

## Guided 


### 1. Array 3 Dimensi

```C++
#include <iostream>
using namespace std;
// Program input Array 3 dimensi
int main ()
{
    // Deklarasi Array //
    int array[2][3][4];
    // Input Elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> array[x][y][z];
            }
        }
        cout << endl;
    }
    // Output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << array[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilam Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << array[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Program yang mendeklarasikan, memasukkan, menampilkan, dan mencetak sebuah array 3 dimensi. Array 3 dimensi ini memiliki ukuran 2x3x4 berarti terdiri dari 2 buah array 2 dimensi, setiap array 2 dimensi terdiri dari 3 buah array 1 dimensi, dan setiap array 1 dimensi terdiri dari 4 elemen. Berikut adalah detail program:

- Deklarasi array 3 dimensi dengan nama `array` dan ukuran 2x3x4.
- Dalam looping for yang meliputi `x` (batas atasnya 2), `y` (batas atasnya 3), dan `z` (batas atasnya 4), program akan menginput elemen array dengan perintah `cin`.
- Dalam looping for yang sama, program akan menampilkan elemen array yang sudah diinput menggunakan `cout`.
- Setelah itu, program akan menampilkan semua elemen array secara horizontal dengan menggunakan `cout` dan `ends` untuk memisahkan elemen.
- Setelah dilakukan looping, maka semua elemen array telah ditampilkan dan diprint ke layar.


### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan Panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << "angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array [0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << " Nilai Maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Program ini adalah program C++ yang digunakan untuk mencari nilai maksimum dari suatu array. Ketika program dijalankan, user akan diminta untuk memasukkan panjang array. Setelah itu, user akan diminta untuk memasukkan elemen-elemen array. Kemudian, program akan menentukan nilai maksimum dari array tersebut dan lokasinya (index). Nilai maksimum dan lokasinya akan ditampilkan ke layar saat program selesai dieksekusi. Variabel yang digunakan dalam program ini antara lain `maks`, `a`, `i`dan `lokasi`. `maks` digunakan untuk menyimpan nilai maksimum, `a` digunakan untuk menyimpan panjang array, `i` digunakan sebagai indeks array, dan `lokasi` digunakan untuk menyimpan lokasi dari nilai maksimum. Perulangan `for` digunakan untuk melakukan iterasi pada setiap elemen di array, dan operasi penugasan digunakan untuk mengupdate nilai maksimum jika elemen tersebut lebih besar.

## Unguided 

#### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
- Array:
- Nomer Genap:
- Nomor Ganjil:

```C++
#include <iostream>
using namespace std;

int main()
{
    int genap[100], ganjil[100], jumlah_genap = 0, jumlah_ganjil = 0, a, i = 1;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka:\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    cout << "Data Array: ";
    for (i = 0; i < a; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
    for (i = 0; i < a; i++)
    {
        if (array[i] % 2 == 0)
        {
            genap[jumlah_genap] = array[i];
            jumlah_genap++;
        }
        else
        {
            ganjil[jumlah_ganjil] = array[i];
            jumlah_ganjil++;
        }
    }
    cout << "\nNomor genap: ";
    for (i = 0; i < jumlah_genap; i++)
    {
        cout << genap[i] << " ";
    }
    cout << "\nNomor ganjil: ";
    for (i = 0; i < jumlah_ganjil; i++)
    {
        cout << ganjil[i] << " ";
    }
    cout << endl;
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
- `int array[a];`: Mendeklarasikan array dengan panjang yang telah diinpus pengguna.
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

#### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

int main() {
    // Input array dimensions
    int length, width, height;
    cout << "Masukkan panjang array: ";
    cin >> length;
    cout << "Masukkan lebar array: ";
    cin >> width;
    cout << "Masukkan tinggi array: ";
    cin >> height;

    // Deklarasi Array //
    int array[length][width][height];

    // Input Elemen
    for (int x = 0; x < length; x++) {
        for (int y = 0; y < width; y++) {
            for (int z = 0; z < height; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> array[x][y][z];
            }
        }
        cout << endl;
    }

    // Output array
    for (int x = 0; x < length; x++) {
        for (int y = 0; y < width; y++) {
            for (int z = 0; z < height; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << array[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilam Array
    for (int x = 0; x < length; x++) {
        for (int y = 0; y < width; y++) {
            for (int z = 0; z < height; z++) {
                cout << array[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
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

#### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan Panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array [0];
    lokasi = 0;
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << " Nilai Maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
    int min = array[0];
    lokasi = 0;
    for (i = 0; i < a; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            lokasi = i;
        }
    }
    cout << " Nilai Minimum adalah " << min << " berada di Array ke " << lokasi << endl;
    double sum = 0;
    for (i = 0; i < a; i++)
    {
        sum += array[i];
    }
    double average = sum / a;
    cout << " Rata-rata nilai adalah " << average << endl;
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
