# <h1 align="center">Laporan Praktikum Modul 5 Struct</h1>
<p align="center">2311110021 / Fauzan  Arrizal / Sains Data</p>

## Dasar Teori

#### 1. Pengertian Struct

Struct dalam C++ adalah tipe data yang terdiri dari beberapa variabel dengan tipe data yang berbeda. Struct dapat digunakan untuk mengelompokkan data yang terkait menjadi satu kesatuan yang lebih kompleks [1].

#### 2. Deklarasi pada Struct

Deklarasi struct dilakukan dengan menggunakan kata kunci `struct` diikuti dengan nama struct dan nama-nama variabel yang akan menjadi anggota struct [1]. Contoh:
```C++
struct Mahasiswa {
    string nama;
    int nim;
    string kelas;
};
```

#### 3. Penggunaan Struct

Struct dapat digunakan untuk menyimpan data yang terstruktur, seperti data mahasiswa, data buku, dan lainnya. Struct juga dapat digunakan sebagai parameter fungsi, sebagai elemen dalam array, atau sebagai variabel [1].

#### 4. Akses ke Anggota Struct

Anggota struct dapat diakses menggunakan nama anggota struct [1]. Contoh:
```C++
Mahasiswa mhs;
mhs.nama = "Ojan";
mhs.nim = 2311110021;
mhs.kelas = "SD04 A"
```

## Guided 
### 1.
```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```

Output:
![Screenshot (396)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/46c0174b-ba68-4b56-a86a-e602f6942785)

Penjelasan:

- `struct buku {};`: mendefinisikan struktur buku seperti judul, pengarang, penerbit, jumlah halaman, harga, dan lainnya.
- `int main()`: merupakan fungsi utama program.
- `buku favorit;`: mendeklarasikan variabel favorit dengan tipe buku.
- `favorit.judulBuku = "";`: mengisi nilai atribut judulBuku dari variabel favorit.
- `favorit.pengarang = "";`: mengisi nilai atribut pengarang dari variabel favorit.
- `favorit.penerbit = "";`: mengisi nilai atribut penerbit dari variabel favorit.
- `favorit.tebalHalaman = ;`: mengisi nilai atribut tebalHalaman dari variabel favorit.
- `favorit.hargaBuku = ;`: mengisi nilai atribut hargaBuku dari variabel favorit.
- `cout << "\tBuku Favorit Saya" << endl;`: menampilkan teks "Buku Favorit Saya" di layar.
- `cout << "\tJudul Buku : " << favorit.judulBuku << endl;`: menampilkan judul buku favorit dari variabel favorit.
- `cout << "\tPengarang : " << favorit.pengarang << endl;`: menampilkan pengarang buku favorit dari variabel favorit.
- `cout << "\tPenerbit : " << favorit.penerbit << endl;`: menampilkan penerbit buku favorit dari variabel favorit.
- `cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;`: menampilkan tebal halaman buku favorit dari variabel favorit.
- `cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;`: menampilkan harga buku favorit dari variabel favorit.
- `return 0;`: mengembalikan nilai 0, menandakan bahwa program telah berakhir.

### 2.

```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
Output:
![Screenshot (397)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/e7167a86-ebb9-4f1e-aa0a-fe83e5dc7fe5)


Penjelasan:

Program mendefinisikan tiga struktur: hewan, hewanDarat, dan hewanLaut. Setelah itu, dilakukan instansiasi dari masing-masing struktur untuk merepresentasikan kelinci, ikan, dan serigala.


## Unguided 

#### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan!

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku[0] = "Home Sweet Loan";
    favorit.pengarang[0] = "Almira Bartari";
    favorit.penerbit[0] = "Gramedia";
    favorit.tebalHalaman[0] = 312;
    favorit.hargaBuku[0] = 71000;

    favorit.judulBuku[1] = "Pagi di Amerika";
    favorit.pengarang[1] = "Hikmat Darmawan";
    favorit.penerbit[1] = "Serambi";
    favorit.tebalHalaman[1] = 180;
    favorit.hargaBuku[1] = 18000;

    favorit.judulBuku[2] = "Pulang";
    favorit.pengarang[2] = "Leila S. Chudori";
    favorit.penerbit[2] = "Gramedia";
    favorit.tebalHalaman[2] = 480;
    favorit.hargaBuku[2] = 90000;

    favorit.judulBuku[3] = "Laut Bercerita";
    favorit.pengarang[3] = "Leila S. Chudori";
    favorit.penerbit[3] = "Gramedia";
    favorit.tebalHalaman[3] = 220;
    favorit.hargaBuku[3] = 80000;

    favorit.judulBuku[4] = "Lima Sentimeter";
    favorit.pengarang[4] = "Donny Dhirgantoro";
    favorit.penerbit[4] = "Grasindo";
    favorit.tebalHalaman[4] = 81;
    favorit.hargaBuku[4] = 100000;

    // Menampilkan informasi buku favorit
    cout << "\t>> Buku Favorit Saya <<" << endl;
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\t>> Buku ke-" << i + 1 << endl;
        cout << "\tJudul Buku       : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang        : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit         : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman    : " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku       : Rp " << favorit.hargaBuku[i] << endl;
        cout << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot (398)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/fc802b0d-f42e-43d1-ae09-96dffc560df1)
![Screenshot (399)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/e7716a14-c423-4115-b8b9-2c421e75a8cd)



Penjelasan:

1. `struktur buku` didefinisikan dengan beberapa atribut seperti judul buku, pengarang, penerbit, tebal halaman, dan harga, masing-masing sebagai array dengan ukuran 5.
2. Pada fungsi `main`, sebuah variabel `favorit` dari tipe buku dideklarasikan.
3. Data diisi ke dalam array-array `favorit.judulBuku`, `favorit.pengarang`, `favorit.penerbit`, `favorit.tebalHalaman`, dan `favorit.hargaBuku` untuk mewakili informasi tentang buku-buku favorit.
Melalui loop `for`, setiap buku dari variabel `favorit` ditampilkan ke layar dengan menggunakan `cout`, menampilkan judul, pengarang, penerbit, tebal halaman, dan harga buku masing-masing.

#### 2.  Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I berjenis Array. Bagaimana cara mengisi data dan menampilkannya?

Dengan menggunakan struktur yang berjenis array, kita dapat dengan mudah mengelola dan mengakses data dalam satu kesatuan, dalam hal ini, kumpulan buku favorit. Ini memudahkan pengelolaan data yang terkait dan menyediakan fleksibilitas dalam mengolah data secara berulang. Contoh:

```C++
#include <iostream>
using namespace std;

// Mendefinisikan struktur buku dengan tipe data array
struct buku {
    string judulBuku[2];
    string pengarang[2];
    string penerbit[2];
    int tebalHalaman[2];
    int hargaBuku[2];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    for (int i = 0; i < 2; ++i) {
        cout << "Masukkan informasi buku ke-" << i+1 << endl;
        cout << "Judul: ";
        getline(cin, favorit.judulBuku[i]);
        cout << "Pengarang: ";
        getline(cin, favorit.pengarang[i]);
        cout << "Penerbit: ";
        getline(cin, favorit.penerbit[i]);
        cout << "Tebal Halaman: ";
        cin >> favorit.tebalHalaman[i];
        cout << "Harga Buku: ";
        cin >> favorit.hargaBuku[i];
        cin.ignore(); // Membersihkan buffer input
        cout << endl;
    }

    // Menampilkan informasi buku favorit
    cout << "\t>> Buku Favorit Saya <<" << endl;
    cout << endl;
    for (int i = 0; i < 2; ++i) {
        cout << "\t>> Buku ke-" << i + 1 << endl;
        cout << "\tJudul Buku       : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang        : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit         : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman    : " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku       : Rp " << favorit.hargaBuku[i] << endl;
        cout << endl;
    }

    return 0;
}
```
Output:
![Screenshot (395)](https://github.com/FauzanArrizal/Algoritma-dan-Struktur-Data-Assignment/assets/161549586/f538ddd3-cbbd-4caa-ada3-64d2def08ac1)


Penjelasan:

Program ini mendefinisikan sebuah struktur bernama `buku` yang memiliki lima anggota, masing-masing merupakan array dengan panjang 2. Anggota-anggota ini mewakili informasi tentang dua buku.

Pada fungsi `main()`, program mengisi data untuk dua buku ke dalam variabel `favorit` menggunakan loop `for`. Setiap iterasi loop meminta pengguna memasukkan informasi tentang buku, seperti judul, pengarang, penerbit, tebal halaman, dan harga buku. Setelah data dimasukkan, program menampilkan informasi buku favorit dengan melakukan iterasi melalui variabel `favorit` dan mencetak informasi setiap buku ke layar.


## Kesimpulan
Struct dalam C++ adalah tipe data yang memungkinkan pengelompokkan beberapa variabel dengan tipe data yang berbeda menjadi satu kesatuan yang lebih kompleks. Deklarasi struct dilakukan dengan menyebutkan kata kunci `struct` diikuti oleh nama struct dan anggota-anggota variabelnya. Struct digunakan untuk menyimpan data terstruktur seperti data mahasiswa atau data buku. Anggota-anggota struct dapat diakses menggunakan nama struct yang diikuti dengan nama anggota struct tersebut. Dengan demikian, struct memberikan kemampuan yang berguna untuk mengorganisir dan mengelola data secara terstruktur dalam program C++.

## Referensi

[1] Bjarne Stroustrup. *The C++ Programming Language*. Addison-Wesley Professional. 2000
