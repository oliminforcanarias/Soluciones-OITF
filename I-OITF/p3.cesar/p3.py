import sys

for line in sys.stdin:
    linea = line.strip().split()

    if len(linea) != 2:
        print ("ERROR")
    else:
        a = linea[0]
        b = linea[1]
        result = []
        if a.isnumeric() and b.isnumeric():
            for i in str(a):
                result.append((int(i)+int(b))%10)
            print(str("".join(map(str, result))))
        else:
            print("ERROR")