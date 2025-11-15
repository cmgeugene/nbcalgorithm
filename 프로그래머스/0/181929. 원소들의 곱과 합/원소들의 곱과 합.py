import math

def solution(num_list):
    sums = sum(num_list) ** 2
    muls = math.prod(num_list)
    if muls < sums:
        return 1
    else : return 0
    