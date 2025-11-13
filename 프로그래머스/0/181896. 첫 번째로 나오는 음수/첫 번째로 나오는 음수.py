def solution(num_list):
    for index, value in enumerate(num_list) :
        if value < 0 : 
            return index
    return -1
    