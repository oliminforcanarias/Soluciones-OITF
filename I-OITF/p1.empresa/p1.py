import sys

for line in sys.stdin:
    codigo = line.strip()

    if len(codigo) != 8 or not codigo[0].isupper() or not codigo[1:].isdigit():
        print("ERROR")
    else:
        suma = 0
        factores_peso = [1, 4, 2, 3, 9, 7, 1]
        letras = ['X', 'D', 'F', 'P', 'L', 'M', 'T', 'H', 'A', 'E']

        for i, numero in enumerate(codigo[1:]):
            suma += int(numero) * factores_peso[i]

        letra_control = letras[suma % 10]

        print(codigo+letra_control)