#include <iostream>
#include <cstring>

struct WordPair{

    std::string english;
    std::string korean;
};

int main() {

    WordPair wordPairs[3];

    wordPairs[0].english = "Hello";
    wordPairs[0].korean = "안녕하세요";

    wordPairs[1].english = "Thank you";
    wordPairs[1].korean = "감사합니다";

    wordPairs[2].english = "Goodbye";
    wordPairs[2].korean = "안녕히 가세요";

    for (int i = 0; i < 3; ++i) {
        std::cout << "English: " << wordPairs[i].english << ", Korean: " << wordPairs[i].korean << std::endl;
    }

    return 0;
}

