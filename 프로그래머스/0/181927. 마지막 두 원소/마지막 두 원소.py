def solution(num_list):
    newlist = list(num_list)
    if newlist[-1] > newlist[-2] :
        newlist.append(newlist[-1]-newlist[-2])
    else : newlist.append(newlist[-1] * 2)
    return newlist