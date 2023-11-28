def grading(m):
    if m < 0 : return "outside range"
    grade = ["F","D","C","B","A"]
    x = [50,60,70,80,101]
    for i in range(5):
        if m < x[i] :
            return(grade[i])
    else : return "outside range"

score = float(input("Enter a marks : "))
print("Your grade : ",grading(score))