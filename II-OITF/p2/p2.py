import sys

for line in sys.stdin:
    x = line.strip()
    y=""
    for i in range(len(x)):
        for char in range(ord('a'), ord(x[i]) + 1):
            print(y+chr(char))
        y=y+x[i]