score = float(input("Enter a score : "))
if score < 0 :
    print("outside range")
elif score < 50 :
    print("Your grade : F")
elif score < 60 :
    print("Your grade : D")
elif score < 70 :
    print("Your grade : C")
elif score < 80 :
    print("Your grade : B")
elif score <= 100 :
    print("Your grade : A")
else :
    print("outside range")