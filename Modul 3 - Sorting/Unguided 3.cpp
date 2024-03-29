#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Masukkan bilangan <n>: ";
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Karakter ke-" << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "\nUrutan karakter sebelum sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "    ";
    }
    sort(arr.begin(), arr.end());
    cout << "\nUrutan karakter setelah ascending sort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "    ";
    }
    sort(arr.begin(), arr.end(), greater<char>());
    cout << "\nUrutan karakter setelah descending sort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "    ";
    }
    return 0;
}