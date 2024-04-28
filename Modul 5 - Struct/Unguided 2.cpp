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
