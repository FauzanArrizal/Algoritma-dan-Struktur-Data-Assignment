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