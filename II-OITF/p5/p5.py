import sys

def calculate_sum(n, k):
    result = 0
    for i in range(1, k+1):
        result += n // i
    return result

for line in sys.stdin:
    total_distance = int(line.split()[0])
    bounces = int(line.split()[1])

    left, right = 0, total_distance
    while right - left > 1:
        middle = (right + left) // 2
        current_sum = calculate_sum(middle, bounces)
        
        if current_sum < total_distance:
            left = middle
        else:
            right = middle

    if calculate_sum(right, bounces) == total_distance:
        print(int(right))
    else:
        print("ERROR")
