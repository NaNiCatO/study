# solving an inequality
def largest_x(y):

    left = 0
    right = y
    
    while left <= right:
        mid = (left + right) // 2
        if mid * mid + mid <= y:
            left = mid + 1
        else:
            right = mid - 1
    
    return right


y = int(input())

print(largest_x(y))
