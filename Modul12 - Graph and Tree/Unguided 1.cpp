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
