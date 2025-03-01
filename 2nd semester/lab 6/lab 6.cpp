#include <iostream>
#include <string>

void Check(std::string message, std::string word) {
    size_t count = 0;
    for (std::string::size_type i = 0; i < message.length(); i++) {
        if (message[i] == word[0]) {
            if (message.substr(i, word.length()) == word) {
                count++;
                i += word.length() - 1;
            }
        }
    }
    if (count == 1) {
        std::cout << word << std::endl;
    }
}

int main()
{
    std::string message;
    std::getline(std::cin, message);
    std::string word;
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == ' ') {
            Check(message, word);
            word = "";
        }
        else {
            word += message[i];
        }
    }
    Check(message, word);
    return 0;
}