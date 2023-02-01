import sys

for line in sys.stdin:
    result = line.strip()

    if result.isnumeric() and int(result) > 0:
        result=int(result)
        suma = 0
        for i in range(1, int(result ** 0.5) + 1):
            if result % i == 0:
                suma += i
                if i != result // i:
                    suma += result // i
        suma -= result
        if suma == result:
            print("PERFECTO")
        else:
            print("NO PERFECTO")
    else:
        print("ERROR")