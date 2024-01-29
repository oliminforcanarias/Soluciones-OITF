import sys

for line in sys.stdin:
    x = line.strip().split()
    minutos = 0
    if x[5] == "fijo":
        if float(x[4]) >= float(x[0]):
            minutos = (float(x[4]) - float(x[0])) // float(x[2])
        else:
            minutos = 0
    else:
        if float(x[4]) >= float(x[1]):
            minutos = (float(x[4]) - float(x[1])) // float(x[3])
        else:
            minutos = 0
    if minutos == 0:
        print("Saldo insuficiente")
    else:
        print(int(minutos))