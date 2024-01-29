#include <iostream>

int calculate_sum(int n, int k) {
    int result = 0;
    for (int i = 1; i <= k; ++i) {
        result += n / i;
    }
    return result;
}

int main() {
    int total_distance, bounces;

    while (std::cin >> total_distance >> bounces) {
        int left = 0, right = total_distance;
        while (right - left > 1) {
            int middle = (right + left) / 2;
            int current_sum = calculate_sum(middle, bounces);

            if (current_sum < total_distance) {
                left = middle;
            } else {
                right = middle;
            }
        }

        if (calculate_sum(right, bounces) == total_distance) {
            std::cout << right << std::endl;
        } else {
            std::cout << "ERROR" << std::endl;
        }
    }

    return 0;
}
