# <h1 align="center">Laporan Praktikum Modul 10 Rekursif</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Rekursif

Rekursif adalah suatu konsep di mana suatu fungsi memanggil dirinya sendiri secara terus-menerus hingga mencapai suatu kondisi dasar yang ditentukan. Rekursif digunakan untuk menyelesaikan masalah yang kompleks dengan cara membagi masalah menjadi beberapa bagian yang lebih kecil dan menyelesaikan masing-masing bagian secara rekursif [1].

#### 2. Rekursif Langsung dan Tidak Langsung

Perbedaan antara rekursif langsung dan tidak langsung adalah cara fungsi memanggil dirinya sendiri. Rekursif langsung memanggil dirinya sendiri secara langsung, sedangkan rekursif tidak langsung memanggil dirinya sendiri secara tidak langsung melalui fungsi lain. Rekursif langsung lebih mudah dipahami dan digunakan, namun memerlukan stack yang lebih besar untuk menampung variabel lokal dan fungsi yang dipanggil. Rekursif tidak langsung lebih kompleks dan memerlukan lebih banyak kode untuk implementasinya, namun dapat digunakan untuk menghitung nilai yang lebih kompleks [2].

#### 3. Kelebihan dan Kekurangan Rekursif

Kelebihan Rekursif:
- Mudah dalam Implementasi: Rekursif dapat digunakan untuk menyelesaikan masalah yang kompleks dengan cara membagi masalah menjadi beberapa bagian yang lebih kecil dan menyelesaikan masing-masing bagian secara rekursif [3].
- Efisiensi: Rekursif dapat digunakan untuk menyelesaikan masalah yang kompleks dengan cara membagi masalah menjadi beberapa bagian yang lebih kecil dan menyelesaikan masing-masing bagian secara rekursif [3].
- Menghemat Ruang Memori: Rekursif dapat digunakan untuk menyelesaikan masalah yang kompleks dengan cara membagi masalah menjadi beberapa bagian yang lebih kecil dan menyelesaikan masing-masing bagian secara rekursif [3].

Kekurangan Rekursif
- Kemungkinan Overflow: Rekursif dapat menyebabkan overflow jika fungsi memanggil dirinya sendiri secara terus-menerus tanpa batas, sehingga dapat menyebabkan program crash [3].
- Kemungkinan Error: Rekursif dapat menyebabkan error jika fungsi tidak didefinisikan dengan benar atau jika fungsi tidak dapat menyelesaikan masalah yang diberikan [3].
- Kemungkinan Tidak Berhenti: Rekursif dapat menyebabkan fungsi tidak berhenti jika tidak ada kondisi yang membatasi pengulangan, sehingga dapat menyebabkan program tidak berhenti [3].

#### 4. Base Case dan Recursive Case

Base case adalah kondisi yang menentukan kapan rekursi harus berhenti. Jika tidak ada base case, maka akan terjadi infinite loop. Recursive case adalah bagian rekursif, di mana fungsi memanggil dirinya sendiri [4]

#### 5. Demonstrasi Rekursi (recursion) dengan program Faktorial

Untuk mendemonstrasikan sebuah rekursi, kita membuat program untuk menghitung nilai faktorial dari suatu bilangan bulat (integer).
Faktorial dari suatu bilangan biasanya dilambangkan sebagai n!, yang mana n merupakan bilangan tersebut [2].

contoh :
5! = 5 x 4 x 3 x 2 x 1 = 120

## Guided

### 1.
```C++
#include <iostream>
using namespace std;

//Code ini berfungsi untuk melakukan hitung mundur
//dari angka yang diinputkan

void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursi Langsung: ";
    countdown(5); //5 merupakan input nya
    cout << endl;
    return 0;
}
```

Output:
![Screenshot (472)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/6b67fb06-0641-4d33-b70d-ab3bf6bae91d)

Penjelasan:

Program ini melakukan hitung mundur dari angka yang diinputkan menggunakan rekursi langsung. Fungsi `countdown` menggunakan pendekatan rekursif untuk mencapai tujuannya. Rekursi adalah proses di mana fungsi memanggil dirinya sendiri. Dalam program ini, `countdown` memanggil dirinya sendiri dengan nilai `n - 1` sampai mencapai kondisi dasar di mana `n` sama dengan 0. Pada setiap langkah rekursi, fungsi mencetak nilai `n` dan kemudian memanggil dirinya sendiri lagi dengan nilai yang berkurang satu. Proses ini berlanjut hingga mencapai kondisi dasar `if (n == 0)`, yang menghentikan rekursi. Saat `countdown(5)` dipanggil dalam fungsi `main`, angka 5 akan dicetak, kemudian fungsi akan memanggil dirinya sendiri dengan nilai 4, dan seterusnya hingga mencetak angka 1 dan berhenti.

### 2.
```C++
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```

Output:
![Screenshot (473)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/55ebae75-cc70-4fbd-ab0e-b5365420ec71)

Penjelasan:

Program ini menggunakan rekursi tidak langsung untuk melakukan hitung mundur, dengan dua fungsi `functionA` dan `functionB` yang saling memanggil satu sama lain. `functionA` mencetak nilai `n` dan memanggil `functionB` dengan `n - 1` jika `n` lebih besar dari 0, sementara `functionB` mencetak nilai `n` dan memanggil `functionA` dengan `n / 2` jika `n` lebih besar dari 0. Dalam fungsi `main`, program memulai dengan memanggil `functionA` dengan nilai awal 5, yang menghasilkan serangkaian panggilan rekursif antara kedua fungsi hingga kondisi dasar tercapai. 

## Unguided 

#### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>

using namespace std;

long long faktorial(int n) {
    if (n == 0) { 
        return 1;
    } else {  
        return n * faktorial(n - 1);
    }
}

int main() {
    int bilangan;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    if (bilangan < 0) {
        cout << "Error: Bilangan harus positif!" << endl;
        return 1; 
    }

    long long hasil = faktorial(bilangan);

    cout << bilangan << " Faktorial dari " << bilangan << " adalah: " << hasil << endl;

    return 0;
}
```
#### Output:
![Screenshot (474)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/f50587c7-1f8f-4687-a169-8c7d2af66139)

Penjelasan:

Program ini menggunakan rekursi untuk menghitung faktorial dari suatu bilangan bulat positif. Fungsi `faktorial` mendefinisikan perhitungan faktorial secara rekursif: jika input `n` adalah 0, fungsi mengembalikan 1 sebagai kasus dasar, sedangkan untuk nilai `n` lainnya, fungsi mengembalikan `n` dikalikan dengan hasil pemanggilan dirinya sendiri dengan `n - 1`. Dalam fungsi `main`, program meminta pengguna untuk memasukkan bilangan bulat positif. Jika bilangan yang dimasukkan kurang dari 0, program menampilkan pesan error dan berhenti. Jika input valid, program menghitung `faktorial` dari bilangan tersebut menggunakan fungsi faktorial dan menampilkan hasilnya. 

#### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
#include <iostream>

using namespace std;

long long faktorialHelper(int n);
long long faktorial(int n);

long long faktorial(int n) {
    if (n == 0) {  // Kasus basis: faktorial dari 0 adalah 1
        return 1;
    } else {
        return n * faktorialHelper(n - 1);
    }
}

long long faktorialHelper(int n) {
    return faktorial(n);
}

int main() {
    int bilangan;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    if (bilangan < 0) {
        cout << "Error: Bilangan harus positif!" << endl;
        return 1;
    }

    long long hasil = faktorial(bilangan);

    cout << bilangan << " Faktorial dari " << bilangan << " adalah: " << hasil << endl;

    return 0;
}

```
#### Output:
![Screenshot (475)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/5547a645-fa42-4c9d-b4e3-2414d63f390a)

Penjelasan:

Program ini menggunakan rekursi tidak langsung untuk menghitung faktorial dari suatu bilangan bulat positif. Dua fungsi, yaitu `faktorial` dan `faktorialHelper`, digunakan untuk melakukan perhitungan. Dalam fungsi `faktorial`, terdapat penanganan untuk kasus dasar di mana nilai faktorial dari 0 adalah 1, sedangkan untuk nilai lainnya, hasil faktorial dihitung dengan mengalikan `n` dengan hasil dari pemanggilan `faktorialHelper` dengan `n - 1`. Fungsi `faktorialHelper` hanya bertugas memanggil kembali fungsi faktorial dengan nilai yang diberikan, menciptakan rekursi tidak langsung antara keduanya. Dalam fungsi `main`, program meminta pengguna memasukkan bilangan bulat positif dan memeriksa apakah bilangan tersebut valid. Jika bilangan negatif dimasukkan, program akan menampilkan pesan error dan menghentikan eksekusi. Namun, jika input valid, program akan menghitung faktorial menggunakan rekursi tidak langsung dan menampilkan hasilnya. 

## Kesimpulan

Rekursif adalah suatu konsep di mana suatu fungsi memanggil dirinya sendiri secara terus-menerus hingga mencapai suatu kondisi dasar yang ditentukan. Rekursif digunakan untuk menyelesaikan masalah yang kompleks dengan cara membagi masalah menjadi beberapa bagian yang lebih kecil dan menyelesaikan masing-masing bagian secara rekursif. Kelebihan rekursif adalah mudah dalam implementasi, efisiensi, dan menghemat ruang memori, namun kekurangan rekursif adalah kemungkinan overflow, kemungkinan error, dan kemungkinan tidak berhenti. Rekursif langsung memanggil dirinya sendiri secara langsung, sedangkan rekursif tidak langsung memanggil dirinya sendiri secara tidak langsung melalui fungsi lain. Rekursif dapat digunakan untuk menyelesaikan masalah yang kompleks, seperti mencari nilai pangkat dan menghitung nilai faktorial, serta beberapa proses deret lainnya.

## Referensi

[1] Joseph Teguh Santoso. *Struktur Data dan Algoritma*. Yayasan Primaagus Teknik. Semarang. 2021


[2] IDCSharp.com. *Rekursif (Recursions) Dalam Algoritma Pemrograman C/C++*. Available:
https://koding123.blogspot.com/2016/03/belajer-bahasa-pemrograman-Recursion-dalam-algoritma.html

[3] Dewi. *Pengertian, Jenis-jenis, Contoh, Kelebihan dan Kekurangan Struktur Data*. 2019. Available: https://dewikhrnnsa.blogspot.com/2019/02/pengertian-dan-jenis-jenis-struktur.html

[4] Fasilkom UI. *Dasar-Dasar Pemrograman 2*. Available: 
http://elearning.ai-innovation.id/pluginfile.php/77/mod_resource/content/1/DDP2_04_Jumat.pdf
