#include <iostream>
#include <vector>

using namespace std;

int sequentialSearch(const vector<int>& data, int key) {
    int count = 0;
    for (int num : data) {
        if (num == key) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int key = 4;

    int count = sequentialSearch(data, key);

    cout << "Banyaknya angka " << key << " pada data adalah: " << count << endl;

    return 0;
}