#include <iostream>
#include <sstream>

void cambio_base(int n, int b) {
    if (n == 0) {
        std::cout << "0" << std::endl;
        return;
    }

    int resultado[32];
    int indice = 0;

    while (n > 0) {
        resultado[indice++] = n % b;
        n /= b;                      
    }

    for (int i = indice - 1; i >= 0; --i) {
        std::cout << resultado[i];
    }
    std::cout << std::endl;
}

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        int n = 0, b = 0;
        bool error = false;

        std::stringstream ss(line);
        if (!(ss >> n >> b)) {
            error = true;
        }

        if (!error && b > 1 && b < 11 && n > 0) {
            cambio_base(n, b);
        } else {
            std::cout << "ERROR" << std::endl;
        }
    }
    return 0;
}