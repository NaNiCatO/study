from fastapi import FastAPI, Form, Request
from fastapi.responses import HTMLResponse, FileResponse, JSONResponse, RedirectResponse
from fastapi.templating import Jinja2Templates

import ZODB, ZODB.FileStorage
import transaction
import BTrees.OOBTree






from class_module import *

storage = ZODB.FileStorage.FileStorage('mydata.fs')
db = ZODB.DB(storage)
connection = db.open()
root = connection.root

root.courses = BTrees.OOBTree.BTree()
root.courses[101] = Course(101, "Computer Programming", 4)
root.courses[201] = Course(201, "Web Programming", 4)
root.courses[202] = Course(202, "Software Engineering Principles", 5)
root.courses[301] = Course(301, "Artificial Intelligent", 3)

h_scoring = [{"Grade": "A", "min": 90 ,"max": 100},
           {"Grade": "B", "min": 80 ,"max": 89},
           {"Grade": "C", "min": 70 ,"max": 79},
           {"Grade": "D", "min": 60 ,"max": 69},
           {"Grade": "F", "min": 0 ,"max": 49}]
l_scoring = [{"Grade": "A", "min": 80 ,"max": 100},
           {"Grade": "B", "min": 60 ,"max": 79},
           {"Grade": "C", "min": 50 ,"max": 59},
           {"Grade": "D", "min": 40 ,"max": 49},
           {"Grade": "F", "min": 0 ,"max": 39}]
root.courses[202].setGradeScheme(h_scoring)
root.courses[301].setGradeScheme(l_scoring)



root.students = BTrees.OOBTree.BTree()
root.students[1101] = Student([], 1101, "Mr. John Doe", "1234")
root.students[1101].enrolls = [Enrollment(root.courses[101], 75, root.students[1101]), Enrollment(root.courses[201], 81, root.students[1101]), Enrollment(root.courses[202], 81, root.students[1101]), Enrollment(root.courses[301], 57, root.students[1101])]


root.students[1102] = Student([], 1102, "Mr. Zhong Li", "5678")
root.students[1102].enrolls = [Enrollment(root.courses[101], 65, root.students[1102]), Enrollment(root.courses[201], 86, root.students[1102]), Enrollment(root.courses[202], 73, root.students[1102])]


root.students[1103] = Student([], 1103, "Mr. Dvalinn Durinson", "9012")
root.students[1103].enrolls = [Enrollment(root.courses[101], 51, root.students[1103]), Enrollment(root.courses[201], 72, root.students[1103]), Enrollment(root.courses[202], 98, root.students[1103]), Enrollment(root.courses[301], 45, root.students[1103])]


transaction.commit()


templates = Jinja2Templates(directory="")
app = FastAPI()

@app.on_event("startup")
async def startup_event():
    # This function will run when the FastAPI app starts
    # Open the ZODB connection and set it as an attribute of the app
    app.state.db = db

@app.on_event("shutdown")
async def shutdown_event():
    # This function will run when the FastAPI app shuts down
    # Close the ZODB connection
    app.state.db.close()

@app.get("/")
async def get_html(request: Request):
    return FileResponse("login.html")


@app.get("/target_uri")
def target_uri():
    return {"message": "You have been redirected to the target URI."}


@app.post("/login")
async def login(request: Request, id: str = Form(...), password: str = Form(...)):
    # Get the student name and ID from the request.
    # return JSONResponse(content={id: password})
    user_name = []
    user_pass = []

    user_data = root.students
    try:
        user_info = user_data[int(id)]
        if user_info.login(password):
            return RedirectResponse(url=f"/form/{id}", status_code=303)
        else:
            return JSONResponse(content={"message": "Wrong password"})
    except KeyError:
        return JSONResponse(content={"message": "Wrong ID"})

    # return JSONResponse(content={"message": user_data[int(id)].password})
    # for user in user_data:
    #     user_name.append(user_data[user].id)
    #     user_pass.append(user_data[user].password)
    #return JSONResponse(content={"message": user_name})
    #     user_info = user_data[user]
    #     if id == str(user_info.id):
    #         if password == user_info.password:
    #             return JSONResponse(content={"id": "Login successfully", })
    # return JSONResponse(content={"id": user_name, "pass": user_pass})


@app.get("/form/{id}")
async def form(request: Request, id: str):
    user_data = root.students
    courses = []
    for enroll in user_data[int(id)].enrolls:
        course = enroll.getCourse()
        courses.append({"code" : course.id, "name" : course.name,"credits" : course.getCredit()})
    
    return templates.TemplateResponse("Transcript.html", {"request": request, "courses" : courses, "id": id, "name": user_data[int(id)].name})

# @app.post("/submit/{id}")
# async def result(request: Request):
#     return JSONResponse(content={"message": "You have been redirected to the target URI."})




@app.post("/submit/{id}")
async def entry(id: int, request: Request):
    
    user_data = root.students[id]
    
    scores = await request.form()
    for key in scores.keys():
        for enroll in user_data.enrolls:
            if int(enroll.course.id) == int(key):
                enroll.score = float(scores[key])
        
    root.students[int(id)] = user_data
    transaction.commit()
    return RedirectResponse(url=f"/transcript/{id}", status_code=303)


@app.get("/transcript/{id}")
async def transcript(id: int, request: Request):
    student = root.students[int(id)]
    data = {
        "student": student,
        "ID": id
    }
    return templates.TemplateResponse("result.html", {"request": request, "data": data})