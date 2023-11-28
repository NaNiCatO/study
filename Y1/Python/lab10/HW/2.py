def bubble_sort(list):
    n = len(list)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if list[j] > list[j + 1]:
                list[j], list[j + 1] = list[j + 1], list[j]
    return list


print(bubble_sort([3,2,9,7,8]))
