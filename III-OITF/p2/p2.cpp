#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int find_number(const std::vector<int>& nums) {
    long long tsum = 0;
    for (int i = nums.front(); i <= nums.back(); ++i) {
        tsum += i;
    }
    long long asum = 0;
    for (auto n : nums) {
        asum += n;
    }
    return tsum - asum;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::vector<int> nums;
        int x;
        while (ss >> x) {
            nums.push_back(x);
        }
        std::cout << find_number(nums) << std::endl;
    }
    return 0;
}