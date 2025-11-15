def solution(a, b):
    ab_val = int(str(a)+str(b))
    ab2 = 2 * a * b
    
    return max(ab_val, ab2)