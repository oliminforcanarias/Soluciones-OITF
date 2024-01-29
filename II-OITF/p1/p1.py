import sys

mult_banco = [4, 8, 5, 10]
mult_entidad = [9, 7, 3, 6]
mult_cuenta = [1, 2, 4, 8, 5, 10, 9, 7, 3, 6]
dc = [0,0]

for line in sys.stdin:
    codigo = line.strip().split()
    suma=0

    if len(codigo) != 3 or len(codigo[0]) != 4 or len(codigo[1]) != 4 or len(codigo[2]) != 10:
        print("IBAN incorrecto")
        continue

    for i in (range(4)):
        suma += int(codigo[0][i]) * mult_banco[i]
    for i in (range(4)):
        suma += int(codigo[1][i]) * mult_entidad[i]

    resto = suma % 11
    dc[0] = 11 - resto
    if dc[0] == 10:
        dc[0] = 1
    elif dc[0] == 11:
        dc[0] = 0

    suma=0
    for i in range(10):
        suma += int(codigo[2][i]) * mult_cuenta[i]
    
    resto = suma % 11
    dc[1] = 11 - resto
    if dc[1] == 10:
        dc[1] = 1
    elif dc[1] == 11:
        dc[1] = 0

    print(codigo[0], codigo[1], str(dc[0])+str(dc[1]), codigo[2])