
my_list = [2, 3, 4, 7, 8]

# recursive binary search returns index of target if cant find target returns -1
def binary_search(list, target):
    if len(list) == 0:
        return -1
    else:
        mid = len(list) // 2
        if list[mid] == target:
            return mid
        else:
            if list[mid] < target:
                return binary_search(list[mid + 1:], target)
            else:
                return binary_search(list[:mid], target)

        


            
print(binary_search(my_list, 9))