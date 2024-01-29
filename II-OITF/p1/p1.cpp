#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::vector<int> mult_banco = {4, 8, 5, 10};
    std::vector<int> mult_entidad = {9, 7, 3, 6};
    std::vector<int> mult_cuenta = {1, 2, 4, 8, 5, 10, 9, 7, 3, 6};
    std::vector<int> dc(2, 0);

    std::string line;

    while (std::getline(std::cin, line)) {
        std::string codigo[3];
        std::istringstream iss(line);
        for (int i = 0; i < 3; ++i) {
            iss >> codigo[i];
        }

        int suma = 0;

        if (codigo[0].size() != 4 || codigo[1].size() != 4 || codigo[2].size() != 10) {
            std::cout << "IBAN incorrecto" << std::endl;
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            suma += (codigo[0][i] - '0') * mult_banco[i];
        }

        for (int i = 0; i < 4; ++i) {
            suma += (codigo[1][i] - '0') * mult_entidad[i];
        }

        int resto = suma % 11;
        dc[0] = 11 - resto;
        if (dc[0] == 10) {
            dc[0] = 1;
        } else if (dc[0] == 11) {
            dc[0] = 0;
        }

        suma = 0;
        for (int i = 0; i < 10; ++i) {
            suma += (codigo[2][i] - '0') * mult_cuenta[i];
        }

        resto = suma % 11;
        dc[1] = 11 - resto;
        if (dc[1] == 10) {
            dc[1] = 1;
        } else if (dc[1] == 11) {
            dc[1] = 0;
        }

        std::cout << codigo[0] << " " << codigo[1] << " " << dc[0] << dc[1] << " " << codigo[2] << std::endl;
    }

    return 0;
}
