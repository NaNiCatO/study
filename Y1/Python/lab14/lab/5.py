def subsetSumZero(list, result = [], Sum = 0):
    if list == []:
        return [x for x in [result] if sum(x) == 0 and x != []]
    else:
        return subsetSumZero(list[1:], result + [list[0]], Sum + list[0]) + subsetSumZero(list[1:], result, Sum)



input = input("Input : ").split(" ")
res = [eval(i) for i in input]
print(subsetSumZero(res))