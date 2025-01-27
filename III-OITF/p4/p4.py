import sys

def is_consec_fib(m, n):
    a, b = 1, 1
    while a <= max(m, n):
        if (a == m and b == n) or (a == n and b == m):
            return True
        a, b = b, a + b
    return False

def assign_sections(n):
    sec1 = []
    sec2 = []
    last_s1 = None

    for num in range(1, n + 1):
        if last_s1 is None:
            sec1.append(num)
            last_s1 = num
        elif is_consec_fib(last_s1, num):
            sec1.append(num)
            last_s1 = num
        else:
            sec2.append(num)

    return sec1, sec2

for line in sys.stdin:
    n = int(line.strip())
    sec1, sec2 = assign_sections(n)
    print(f"Sección 1: {len(sec1)} números")
    print(f"Números: {', '.join(str(x) for x in sec1)}")
    print(f"Sección 2: {len(sec2)} números")
    print(f"Números: {', '.join(str(x) for x in sec2)}")