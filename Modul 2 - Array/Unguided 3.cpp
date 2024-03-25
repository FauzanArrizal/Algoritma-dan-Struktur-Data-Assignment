#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan Panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array [0];
    lokasi = 0;
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << " Nilai Maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
    int min = array[0];
    lokasi = 0;
    for (i = 0; i < a; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            lokasi = i;
        }
    }
    cout << " Nilai Minimum adalah " << min << " berada di Array ke " << lokasi << endl;
    double sum = 0;
    for (i = 0; i < a; i++)
    {
        sum += array[i];
    }
    double average = sum / a;
    cout << " Rata-rata nilai adalah " << average << endl;
}