#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::vector<std::vector<double>> vehiculos_todos;

    double distancia;
    int cantidad_vehiculos;

    if (!(std::cin >> distancia >> cantidad_vehiculos) || distancia <= 0 || cantidad_vehiculos <= 0) {
        std::cout << "ERROR" << std::endl;
        return 0;
    }

    for (int i = 0; i < cantidad_vehiculos; ++i) {
        std::vector<double> vehiculo;
        double id_vehiculo, consumo_por_litro, precio_combustible;

        if (!(std::cin >> id_vehiculo >> consumo_por_litro >> precio_combustible) ||
            id_vehiculo <= 0 || consumo_por_litro <= 0 || precio_combustible <= 0) {
            std::cout << "ERROR" << std::endl;
            return 0;
        }

        double coste = (distancia / consumo_por_litro) * precio_combustible;
        vehiculo = {id_vehiculo, consumo_por_litro, precio_combustible, coste};
        vehiculos_todos.push_back(vehiculo);
    }

    std::sort(vehiculos_todos.begin(), vehiculos_todos.end(), [](const auto &a, const auto &b) {
        return a[3] < b[3];
    });

    std::cout << vehiculos_todos[0][0] << " " << std::fixed << std::setprecision(4)
              << vehiculos_todos[1][3] - vehiculos_todos[0][3] << std::endl;

    return 0;
}