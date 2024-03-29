#include <iostream>
#include <string>

using namespace std;

// Fungsi bubble sort mengurutkan array string dari kecil ke besar
void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void cetak_array(string a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "   ";
    }
    cout << endl;
}

int main() {
    // Array nama warga
    string arr[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Nama-nama warga sebelum diurutkan: ";
    cetak_array(arr, n);
    bubbleSort(arr, n);
    cout << "Nama-nama warga setelah diurutkan: ";
    cetak_array(arr, n);
    return 0;
}