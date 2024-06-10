#include <iostream>

using namespace std;

void bubble_sort(double arr[], int panjang)
{
    bool not_sorted = true;
    int j = 0;
    double tmp;
    while (not_sorted)
    {
        not_sorted = false;
        j++;
        for (int i = 0; i < panjang - j; i++)
        {
            if (arr[i] > arr[i + 1]) 
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    }
}

void cetak_array(double a[], int panjang) 
{
    for(int i = 0; i < panjang; i++) 
    {
        cout << a[i];
    }
    cout << endl;
}


int main() 
{
    int panjang = 5;
    double n[] = {5, 1, 4, 2, 8};    
    cout << "Urutan sebelum sorting: " << endl;
    cetak_array(n, panjang);
    bubble_sort(n, panjang);
    cout << "Urutan setelah menggunakan bubble sort: " << endl;
    cetak_array(n, panjang);
    return 0;
}

