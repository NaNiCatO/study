def binary_search_answer(arr, l, r, x):
    if r >= l:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search_answer(arr, l, mid - 1, x)
        else:
            return binary_search_answer(arr, mid + 1, r, x)
    else:
        return -1
    
def binary_search_approximation(arr, l, r, x):
    if r >= l:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search_approximation(arr, l, mid - 1, x)
        else:
            return binary_search_approximation(arr, mid + 1, r, x)
    else:
        return r
    
test = [1, 2, 3, 4, 7, 8, 9, 10]
print(binary_search_answer(test, 0, len(test)-1, 5))
print(binary_search_approximation(test, 0, len(test)-1, 5))