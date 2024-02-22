def quick_select(arr, k):
    if len(arr) == 1:
        return arr[0]
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    right = [x for x in arr if x > pivot]
    if k < len(left):
        return quick_select(left, k)
    elif k >= len(arr) - len(right):
        return quick_select(right, k - (len(arr) - len(right)))
    else:
        return pivot
    
arr = [3, 2, 1, 5, 4]
k = 2
print(quick_select(arr, k)) # 2