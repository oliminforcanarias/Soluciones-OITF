import sys

def find_number(nums):
    
    tsum = sum(range(nums[0], nums[-1] + 1))
    asum = sum(nums)
    return tsum - asum

for line in sys.stdin:
    nums = []
    for x in line.strip().split():
        nums.append(int(x))
    print(str(find_number(nums)))