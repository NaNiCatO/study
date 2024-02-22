u = input()
v = input()
end = input()



# def opt(m, n):
#     if n == 0:
#         return m
#     if m == 0:
#         return n
#     if u[m] == v[n]:
#         return opt(m-1, n-1)
#     else:
#         return min(opt(m-1, n-1), opt(m-1, n), opt(m, n-1)) + 1


def opt(m, n):
    # Base cases
    if n == 0:
        return m
    if m == 0:
        return n
    
    # If the characters at current positions are equal
    if u[m-1] == v[n-1]:
        return opt(m-1, n-1)
    else:
        # If characters are different, recursively compute minimum
        return min(opt(m-1, n-1),  # Replace
                   opt(m-1, n),    # Delete
                   opt(m, n-1))+1    # Insert

# Example usage:
result = opt(len(u), len(v))
print(result)



# print(opt(len(u)-1, len(v)-1))
# print(opt1(len(u)-1, len(v)-1))