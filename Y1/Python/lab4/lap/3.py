name = input("Enter your name : ")
age = int(input("Enter your age : "))
w = float(input("Enter your weight in Kg : "))
h = float(input("Enter your height in cm : "))/100
bmi = w/(h*h)
if age < 17 :
    print("Your body mass index (BMI) is",format(bmi,".9f"))
    if bmi < 15:
        print(name,"you are underweight")
    elif bmi <= 20 :
        print(name,"you are normal")
    elif bmi > 20 :
        print(name,"you are overweight")
elif age <= 35:
    print("Your body mass index (BMI) is",format(bmi,".9f"))
    if bmi < 18:
        print(name,"you are underweight")
    elif bmi <= 24 :
        print(name,"you are normal")
    elif bmi > 24 :
        print(name,"you are overweight")
elif age > 35:
    print("Your body mass index (BMI) is",format(bmi,".9f"))
    if bmi < 19:
        print(name,"you are underweight")
    elif bmi <= 26 :
        print(name,"you are normal")
    elif bmi > 26 :
        print(name,"you are overweight")