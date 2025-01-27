import sys

def calculate_imei(imei):
    digits = [int(d) for d in str(imei)]

    for i in range(len(digits) - 1, -1, -2):
        digits[i] *= 2
        if digits[i] > 9:
            digits[i] -= 9

    total_sum = sum(digits)

    control = (10 - (total_sum % 10)) % 10

    return control

for line in sys.stdin:
    num = line.strip()
 
    print(str(num)+str(calculate_imei(num)))