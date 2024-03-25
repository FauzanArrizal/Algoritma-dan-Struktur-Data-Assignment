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