def solution(num_list):
    even = []
    odd = []
    for i in num_list:
        s = str(i)
        if i % 2 == 0:
            even.append(s)
        else :
            odd.append(s)
    even_toint = "".join(even)
    odd_toint = "".join(odd)
    return int(even_toint or '0') + int(odd_toint or '0')