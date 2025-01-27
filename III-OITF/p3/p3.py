import sys

def find_numbers(nums):
    nums.sort()
    full_set = set(range(nums[0], nums[-1] + 1))
    m_numbers = full_set - set(nums)
    return sorted(list(m_numbers))

for line in sys.stdin:
    nums = []
    for x in line.strip().split():
        token = x.strip()
        if '.' in token:
            continue
        if (token.startswith('-') and token[1:].isdigit()) or token.isdigit():
            nums.append(int(token))
    result = find_numbers(nums)
    print(' '.join(str(n) for n in result))