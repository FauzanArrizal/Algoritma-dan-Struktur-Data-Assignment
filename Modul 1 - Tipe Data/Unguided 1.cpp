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
