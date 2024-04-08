#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

int countVowels(const string& sentence, unordered_set<char>& vowelsFound) {
    int count = 0;
    for (char ch : sentence) {
        char lowerCh = tolower(ch);
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            count++;
            vowelsFound.insert(ch);
        }
    }
    return count;
}

int main() {
    string sentence;
    unordered_set<char> vowelsFound;

    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    int vowelCount = countVowels(sentence, vowelsFound);

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << vowelCount << endl;

    cout << "Huruf vokal yang ditemukan pada kalimat: ";
    for (char ch : vowelsFound) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}