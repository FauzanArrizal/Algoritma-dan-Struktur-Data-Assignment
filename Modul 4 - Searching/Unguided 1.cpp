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