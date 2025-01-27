import sys

def cambio_base(n, b):
    if n == 0:
        return "0"
    r = ""
    while n > 0:
        r = str(n % b) + r
        n //= b
    return r

for line in sys.stdin:
    nums = line.strip().split()

    if len(nums) == 2:
        if nums[0].isdigit() and nums[1].isdigit() and int(nums[1]) > 1 and int(nums[1]) < 11 and int(nums[0]) > 0:
            print(cambio_base(int(nums[0]), int(nums[1])))
        else:
            print("ERROR")
    else:
        print("ERROR")