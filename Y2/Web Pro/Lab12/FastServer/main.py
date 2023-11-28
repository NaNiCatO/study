from fastapi import FastAPI

app = FastAPI()

students = {
    29 : {"ID": 29, "first_name": "Kazuha", "last_name": "Kaedehara"},
    30 : {"ID": 30, "first_name": "Albedo", "last_name": "Rhinedottir"}
}

@app.get("/")
async def root():
    return {"message": "Hello World"}


@app.get("/path/{path_parameter}")
async def function_name(path_parameter: str):
    return {"path_parameter": path_parameter}


@app.get("/students/all")
async def function_name(path_parameter: str):
    return students