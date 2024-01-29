#include <iostream>
#include <string>

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        std::string x = line;
        std::string y = "";

        for (int i = 0; i < x.length(); ++i) {
            for (char ch = 'a'; ch <= x[i]; ++ch) {
                std::cout << y << ch << std::endl;
            }
            y += x[i];
        }
    }
    return 0;
}