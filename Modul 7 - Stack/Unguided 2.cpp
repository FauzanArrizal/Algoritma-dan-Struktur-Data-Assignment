#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to reverse a sentence using a stack
void reverseSentence(string sentence) {
    stack<char> characters;

    for (char c : sentence) {
        characters.push(c);
    }

    cout << "Hasil: ";
    while (!characters.empty()) {
        cout << characters.top();
        characters.pop();
    }
    cout << endl;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "Kalimat: " << kalimat << endl;

    reverseSentence(kalimat);

    return 0;
}