import sys

lines = sys.stdin.readlines()

distancia = float(lines[0].strip())
cantidad_vehiculos = int(lines[1].strip())
vehiculos_todos = []

if (distancia <= 0 or cantidad_vehiculos <= 0):
    print("ERROR")
    exit()

for i in range(2, cantidad_vehiculos + 2):
    vehiculo = []
    datos_vehiculo = lines[i].strip().split()
    #id_vehiculo
    vehiculo.append(int(datos_vehiculo[0]))
    #consumo_por_litro
    vehiculo.append(float(datos_vehiculo[1]))
    #precio_combustible
    vehiculo.append(float(datos_vehiculo[2]))

    if (vehiculo[0] <= 0 or vehiculo[1] <= 0 or vehiculo[2] <= 0):
        print("ERROR")
        exit()
    #coste
    vehiculo.append((distancia / float(datos_vehiculo[1])) * float(datos_vehiculo[2]))
    vehiculos_todos.append(vehiculo)

vehiculos_todos.sort(key=lambda x: x[3])
print(vehiculos_todos[0][0], "{:.4f}".format(vehiculos_todos[1][3]-vehiculos_todos[0][3]))