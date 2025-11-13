def solution(num_list):
    answer = list()
    index = 0
    for i in num_list :
        if i < 0 : 
            answer.append(index)
            return answer[0]
        index += 1
    return -1
    