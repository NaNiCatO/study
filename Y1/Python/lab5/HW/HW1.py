n = eval(input("Enter number : "))
guess = n/2
for i in range(7):
	temp = n/guess
	guess = (guess + temp)/2
	if i == 4 :
		ans1 = guess
	elif i == 5 :
		ans2 = guess
	elif i == 6 :
		ans3 = guess
print("iterate 5 time",format(ans1,".2f"))
print("iterate 6 time",format(ans2,".2f"))
print("iterate 7 time",format(ans3,".2f"))