#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

int calculate_imei(const std::string& imei) {
    std::vector<int> digits;

    for (char c : imei) {
        digits.push_back(c - '0');
    }

    for (int i = digits.size() - 1; i >= 0; i -= 2) {
        digits[i] *= 2;
        if (digits[i] > 9) {
            digits[i] -= 9;
        }
    }

    int total_sum = 0;
    for (int d : digits) {
        total_sum += d;
    }

    int control = (10 - (total_sum % 10)) % 10;

    return control;
}

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        std::cout << line << calculate_imei(line) << std::endl;
    }
    return 0;
}