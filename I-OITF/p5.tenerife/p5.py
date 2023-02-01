import sys

p = []

for line in sys.stdin:
    linea = line.strip().split()

    if len(linea) != 2 or not linea[0].isdigit() or not linea[1].isdigit():
        print("ERROR")
        exit()

    p.append((int(linea[0]), int(linea[1])))

d = 0
for i in range(0, len(p)-1):
    x1, y1 = p[i]
    x2, y2 = p[i+1]
    d += abs(x1 - x2) + abs(y1 - y2)

print("PUNTOS DE INTERES: " + str(len(p)))
print("DISTANCIA: " + str(d))