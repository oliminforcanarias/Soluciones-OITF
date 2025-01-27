#include <iostream>
#include <vector>

bool is_consec_fib(int m, int n) {
    int a = 1, b = 1;
    while (a <= std::max(m, n)) {
        if ((a == m && b == n) || (a == n && b == m)) {
            return true;
        }
        int next = a + b;
        a = b;
        b = next;
    }
    return false;
}

void assign_sections(int n) {
    std::vector<int> sec1, sec2;
    int last_s1 = 0;
    bool first = true;

    for (int num = 1; num <= n; num++) {
        if (first) {
            sec1.push_back(num);
            last_s1 = num;
            first = false;
        }
        else if (is_consec_fib(last_s1, num)) {
            sec1.push_back(num);
            last_s1 = num;
        }
        else {
            sec2.push_back(num);
        }
    }

    std::cout << "Sección 1: " << sec1.size() << " números\n";
    std::cout << "Números: ";
    for (size_t i = 0; i < sec1.size(); i++) {
        std::cout << sec1[i];
        if (i < sec1.size() - 1) std::cout << ", ";
    }
    
    std::cout << "\nSección 2: " << sec2.size() << " números\n";
    std::cout << "Números: ";
    for (size_t i = 0; i < sec2.size(); i++) {
        std::cout << sec2[i];
        if (i < sec2.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    assign_sections(n);
    return 0;
}