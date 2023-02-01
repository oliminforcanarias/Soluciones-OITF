import sys

def producto(n):
    digitos = [int(d) for d in str(n)]
    producto_maximo = 0.0

    for i in range(len(digitos) - 2):
        producto = digitos[i] * digitos[i+1] * digitos[i+2]
        producto_maximo = max(producto_maximo, producto)

    return producto_maximo

for line in sys.stdin:
    codigo = line.strip()

    if len(codigo) < 3 or not codigo[0:].isdigit():
        print("ERROR")
    else:
        n = int(codigo)
        print(producto(n))