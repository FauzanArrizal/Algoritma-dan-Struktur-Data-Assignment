#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isPalindrome(std::string sentence) {
    std::stack<char> charStack;
    sentence.erase(std::remove_if(sentence.begin(), sentence.end(), ::isspace), sentence.end()); // Menghapus spasi
    std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower); // Mengubah huruf kecil

    for (char c : sentence) {
        charStack.push(c);
    }

    std::string reverseSentence;
    while (!charStack.empty()) {
        reverseSentence += charStack.top();
        charStack.pop();
    }

    return sentence == reverseSentence;
}

int main() {
    std::string kalimat;
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, kalimat);

    if (isPalindrome(kalimat)) {
        std::cout << "Kalimat tersebut adalah palindrom" << std::endl;
    } else {
        std::cout << "Kalimat tersebut bukan palindrom" << std::endl;
    }

    return 0;
}

