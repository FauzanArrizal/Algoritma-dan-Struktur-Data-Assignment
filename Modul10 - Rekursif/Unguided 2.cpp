#include <iostream>

using namespace std;

long long faktorialHelper(int n);
long long faktorial(int n);

long long faktorial(int n) {
    if (n == 0) {  // Kasus basis: faktorial dari 0 adalah 1
        return 1;
    } else {
        return n * faktorialHelper(n - 1);
    }
}

long long faktorialHelper(int n) {
    return faktorial(n);
}

int main() {
    int bilangan;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    if (bilangan < 0) {
        cout << "Error: Bilangan harus positif!" << endl;
        return 1;
    }

    long long hasil = faktorial(bilangan);

    cout << bilangan << " Faktorial dari " << bilangan << " adalah: " << hasil << endl;

    return 0;
}
