n = int(input("Enter integer >1 : "))
x = ""
if n != 1: print("*")
for i in range(n,0,-1):
	for j in range(1,i+1):
		x += ("*")
		if x == "*": continue
		print(x)
	for j in range(i-1):
		x = x[:-1]
		print(x)
	x = x[:-1]
print("*")