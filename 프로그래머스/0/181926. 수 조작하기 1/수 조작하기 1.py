def solution(n, control):
    control_dict = {
        'w' : 1,
        's' : -1,
        'a' : -10,
        'd' : 10
    }
    for char in control:
        n += control_dict.get(char, 0)
    
    return n