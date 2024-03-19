# <h1 align="center">Laporan Praktikum Modul 1 Tipe Data</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

Jika kita berbicara tentang pemrograman, kita tidak bisa melupakan istilah "tipe data", yang merupakan jenis nilai yang akan ditampung oleh sebuah variabel ketika kita membuat variabel agar variabel tersebut memiliki nilai yang jelas dan spesifik ketika digunakan[1].

Tipe data terbagi menjadi tiga bagian  utama, yaitu tipe data primitive, abstrak dan koleksi.

#### 1. Tipe data Primitif
Merupakan tipe data tipe data yang sudah terdefinisi secara bawaan dalam bahasa pemrograman. Tipe data primitif biasanya digunakan untuk menyimpan nilai yang sederhana dan tidak kompleks.
Yang termasuk tipe data primitif yaitu:
- Integer
- Short
- Long integer
- Float
- Double
- Char

#### 2. Tipe data Abstrak
Merupakan tipe data yang digunakan untuk menyimpan dan mengelola data yang lebih kompleks.
Yang termasuk tipe data abstrak yaitu:

- Function
- Array
- Pointer
- Reference
- String

#### 3. Tipe data Koleksi
Merupakan tipe data yang dapat menyimpan beberapa elemen yang sama.
Yang termasuk tipe data koleksi yaitu:

- Class
- Struct
- Union
- Enum
- Typedef


## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
// Main program
main()
{
    char op;
    float num1, num2;
    // It allows user enter operatoe i.e, +, -, *, /
    cin >> op;
    // It alllow user to enter the operands
    cin >> num1 >> num2;
    // switch statement begins
    switch  (op)
    
    {
    //  If user enter +
    case '+':
        cout << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << num1 / num2;
        break;
    // If the operator is other than ....
    // error message will display
    default:
        cout << "Error! operator is not correct";
    }
    return 0;
}
```
Program ini adalah sebuah kalkulator sederhana yang dapat melakukan operasi aritmetika dasar seperti penjumlahan, pengurangan, perkalian, dan pembagian. User dapat memasukkan operator dan dua bilangan, dan program akan melakukan operasi dan menampilkan hasilnya. Jika operator bukan +, -, *, atau /, maka tidak akan melanjutkan program. Kalkulator hanya dapat melakukan operasi pada bilangan desimal.


### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

// struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    // Using struct
    struct Mahasiswa mhs1, mhs2;
    
    // Adding values to struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // Printing struct contents
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama:  %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
Struct digunakan untuk menampung data seperti nama, alamat, dan usia. Dalam kode tersebut, dua variabel struct "mhs1" dan "mhs2" digunakan untuk merepresentasikan informasi individu dari mahasiswa. Setelah nilai-nilai diatur untuk setiap variabel struct, informasi tersebut kemudian dicetak menggunakan printf untuk menampilkan data.


### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
    //Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "isi array pertama :" << nilai[0] << endl;
    cout << "isi array kedua :" << nilai[1] << endl;
    cout << "isi array ketiga :" << nilai[2] << endl;
    cout << "isi array keempat :" << nilai[3] << endl;
    cout << "isi array kelima :" << nilai[4] << endl;
    return 0;
}
```
Program ini menunjukkan cara membuat dan menginisialisasi array, serta cara mencetak nilai-nilai dari array tersebut. Dengan mendeklarasikan sebuah array bernama nilai dengan 5 elemen, dan kemudian menginisialisasi setiap elemen dengan suatu nilai.


## Unguided 

#### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!


```C++
#include <iostream>
using namespace std;

int hitungLuasPersegiPanjang(int panjang, int lebar) {
    return panjang * lebar;
}

float hitungLuasSegitiga(float alas, float tinggi) {
    return 0.5 * alas * tinggi;
}

int main() {
    int panjang, lebar;
    float alas, tinggi;

    // Persegi panjang
    cout << "Masukkan panjang persegi panjang: ";
    cin >> panjang;

    cout << "Masukkan lebar persegi panjang: ";
    cin >> lebar;

    cout << "Luas persegi panjang dengan panjang " << panjang << " dan lebar " << lebar << " adalah: " << hitungLuasPersegiPanjang(panjang, lebar) << endl;

    // Segitiga
    cout << "Masukkan alas segitiga: ";
    cin >> alas;

    cout << "Masukkan tinggi segitiga: ";
    cin >> tinggi;

    cout << "Luas segitiga dengan alas " << alas << " dan tinggi " << tinggi << " adalah: " << hitungLuasSegitiga(alas, tinggi) << endl;

    return 0;
}
```
#### Output:
![Screenshot (334)](https://github.com/FauzanArrizal/Laprak-Modul-1/assets/161549586/626e955f-fb5f-46a3-b183-17a5bd573440)

Penjelasan:

Program ini meminta pengguna untuk memasukkan nilai panjang dan lebar persegi panjang menggunakan fungsi input cin, yang kemudian disimpan dalam variabel panjang dan lebar. Selanjutnya, program menghitung luas persegi panjang dengan memanggil fungsi hitungLuasPersegiPanjang menggunakan nilai panjang dan lebar yang dimasukkan pengguna, dan hasilnya ditampilkan. Setelah itu, program meminta pengguna untuk memasukkan nilai alas dan tinggi segitiga, kemudian menghitung luas segitiga berdasarkan input tersebut menggunakan fungsi hitungLuasSegitiga, dan menampilkan hasil perhitungannya. Kesimpulannya, program ini memungkinkan pengguna untuk menghitung luas persegi panjang dan segitiga berdasarkan input yang mereka berikan.

#### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

#### Class:
Class adalah struktur yang digunakan untuk merepresentasikan objek dalam pemrograman berorientasi objek. Class mengelompokkan data bersama dengan metode yang beroperasi pada data tersebut.

Contoh code:

```C++
#include <iostream>
using namespace std;

class Person {
public:
    const char *name;
    int age;
};

int main() {
    // Membuat objek dari class Person
    Person person;
    person.name = "Ojan";
    person.age = 19;

    // Menampilkan informasi person
    cout << "Nama: " << person.name << ", Usia: " << person.age << endl;

    return 0;
}
```
Output:
![Screenshot (341)](https://github.com/FauzanArrizal/Laprak-Modul-1/assets/161549586/5d7edad5-c2cd-4f39-a8d5-ebd4df8c17fc)

Penjelasan:

'class Person' Mendefinisikan class Person dengan dua atribut, yaitu name bertipe cost char dan age bertipe integer.
'Person person' Membuat objek person dari class Person.
'person.name = "Ojan"' dan 'person.age = 19' Menginisialisasi nilai atribut name dan age dalam objek person.

#### Struct:

Struct (singkatan dari "structure") adalah sebuah tipe data yang digunakan untuk mengelompokkan beberapa variabel dengan tipe data yang berbeda dalam satu unit.

Contoh code:

```C++
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    // Membuat objek 
    Point p1;
    p1.x = 10;
    p1.y = 30;

    // Koordinat p1
    cout << "Point koordinat: (" << p1.x << ", " << p1.y << ")" << endl;

    return 0;
}
```
Output:
![Screenshot (342)](https://github.com/FauzanArrizal/Laprak-Modul-1/assets/161549586/6a3010ae-b0ab-4459-ab63-3d199d700eef)

Penjelasan:
'struct Point' Mendefinisikan struct Point dengan dua variabel bertipe integer, yaitu x dan y.
'Point p1' Membuat objek p1 dari struct Point.
'p1.x = 10' dan 'p1.y = 30' Menginisialisasi nilai dari variabel x dan y dalam objek p1.

#### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
#include <iostream>
#include <map>

int main() {
  // Deklarasi
  std::map<int, std::string> mapEG;

  // Insert
  mapEG[1] = "Spidol";
  mapEG[2] = "Pulpen";
  mapEG[3] = "Pensil";

  std::cout << "Value at key 1: " << mapEG[1] << std::endl;
  std::cout << "Value at key 2: " << mapEG[2] << std::endl;
  std::cout << "Value at key 3: " << mapEG[3] << std::endl;

  return 0;
}
```
#### Output:
![Screenshot (344)](https://github.com/FauzanArrizal/Laprak-Modul-1/assets/161549586/17a4db54-32f6-4559-8a0e-ff3f18817881)

Penjelasan:

Map dengun nama mapEG tipenya sebagai string. Kemudian, tiga pasang key-value di-insert ke dalam map tersebut. Setelah itu, program mencetak nilai dari setiap key dengan menggunakan operator []. Operator ini akan membuat key baru dan menetapkan nilainya jika key belum ada dalam map. Jika key sudah ada, operator ini akan mengembalikan nilainya.

Dalam contoh ini, ketiga key (1, 2, dan 3) telah di-insert sebelumnya, sehingga operator [] hanya akan mengembalikan nilainya saat dipanggil. Nilai dari key 1 adalah "Spidol", key 2 adalah "Pulpen", dan key 3 adalah "Pensil".

## Kesimpulan
Program yang menggunakan tipe data primitif umumnya berfokus pada operasi sederhana dan langsung pada nilai-nilai tunggal, seperti integer, floating point, dan karakter. Contohnya program kalkulator sederhana. Penggunaan tipe data primitif memungkinkan operasi matematika dasar dilakukan dengan mudah dan efisien.

Class dan struct digunakan untuk mengelompokkan data bersama dengan fungsi-fungsi yang beroperasi pada data tersebut. Perbedaannya yaitu pada aksesibilitas default dari atribut dan metode dalam keduanya. Pada class, secara default, atribut dan metode memiliki aksesibilitas private, sedangkan pada struct, secara default, atribut dan metode memiliki aksesibilitas public. Contohnya class Person dan struct Point digunakan untuk merepresentasikan objek dan koordinat.

Array dan map merupakan dua struktur data yang berbeda. Array adalah struktur data yang menyimpan elemen-elemen dengan indeks integer yang berurutan, sedangkan map adalah struktur data yang menyimpan pasangan key-value, dimana setiap key memiliki nilai unik.

## Referensi
[1] Putra MTD, Pradeka D, Yuniarti AR. 2022. Belajar Dasar Pemrograman Dengan C++. Widina.
