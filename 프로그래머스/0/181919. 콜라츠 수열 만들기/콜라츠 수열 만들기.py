def generate_collatz(n):
    yield n
    while n != 1:
        if n % 2 == 0 :
            n //= 2
        else :
            n = (3 * n) + 1
        yield n

def solution(n):
    return list(generate_collatz(n))
    
    