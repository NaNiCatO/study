#Two items
def pairing_item(price, items):
    for i in range(len(items)):
        if binary_search(items, i+1, len(items)-1, price - items[i]) != -1:
            return "Yes"
    return "No"

def binary_search(arr, l, r, x):
    if r >= l:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, l, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, r, x)
    else:
        return -1


coupon = int(input())
list_items = list(map(int, input().split()))
list_items.sort()
print(pairing_item(coupon, list_items))
