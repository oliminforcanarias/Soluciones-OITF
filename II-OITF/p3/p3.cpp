#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        double coste_fijo, coste_movil, minuto_fijo, minuto_movil, saldo;
        std::string tipo;
        iss >> coste_fijo >> coste_movil >> minuto_fijo >> minuto_movil >> saldo >> tipo;

        int minutos = 0;
        if (tipo == "fijo") {
            if (saldo >= coste_fijo) {
                minutos = static_cast<int>((saldo - coste_fijo) / minuto_fijo);
            }
        } else {
            if (saldo >= coste_movil) {
                minutos = static_cast<int>((saldo - coste_movil) / minuto_movil);
            }
        }

        if (minutos == 0) {
            std::cout << "Saldo insuficiente" << std::endl;
        }
        else{
            std::cout << minutos << std::endl;
        }
    }
    return 0;
}