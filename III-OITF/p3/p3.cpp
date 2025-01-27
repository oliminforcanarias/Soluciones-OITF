#include <iostream>
#include <vector>
#include <string>
#include <sstream>

bool esDigito(char c) {
    return (c >= '0' && c <= '9');
}

bool esEntero(const std::string& token) {
    if (token.empty()) return false;
    if (token.find('.') != std::string::npos) return false;

    if (token[0] == '-') {
        if (token.size() == 1) return false;
        for (size_t i = 1; i < token.size(); i++) {
            if (!esDigito(token[i])) {
                return false;
            }
        }
        return true;
    } else {
        for (char c : token) {
            if (!esDigito(c)) {
                return false;
            }
        }
        return true;
    }
}

void bubbleSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = 0; j + 1 < arr.size(); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findMin(const std::vector<int>& arr) {
    int minVal = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int findMax(const std::vector<int>& arr) {
    int maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

bool contains(const std::vector<int>& arr, int val) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == val) return true;
    }
    return false;
}

std::vector<int> find_numbers(std::vector<int>& nums) {
    if (nums.empty()) return {};
    bubbleSort(nums);
    int minVal = findMin(nums);
    int maxVal = findMax(nums);

    std::vector<int> missing;
    for (int i = minVal; i <= maxVal; i++) {
        if (!contains(nums, i)) {
            missing.push_back(i);
        }
    }
    return missing;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<int> nums;

        while (ss >> token) {
            if (esEntero(token)) {
                nums.push_back(std::stoi(token));
            }
        }

        std::vector<int> resultado = find_numbers(nums);

        bool first = true;
        for (int val : resultado) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << val;
            first = false;
        }
        std::cout << "\n";
    }
    return 0;
}