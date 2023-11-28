import persistent

grade = [{"Grade": 4, "Text": "A"},
         {"Grade": 3, "Text": "B"},
         {"Grade": 2, "Text": "C"},
         {"Grade": 1, "Text": "D"},
         {"Grade": 0, "Text": "F"}]

def convert_grade(n):
    for grader in grade:
        if grader["Text"] == n:
            return grader["Grade"]
    return "Invalid Score"


class Course(persistent.Persistent):
    def __init__(self, id, name, credit = 3):
        self.credit = credit
        self.id = id
        self.name = name
        self.grading = [{"Grade": "A", "min": 80 ,"max": 100},
           {"Grade": "B", "min": 70 ,"max": 79},
           {"Grade": "C", "min": 60 ,"max": 69},
           {"Grade": "D", "min": 50 ,"max": 59},
           {"Grade": "F", "min": 0 ,"max": 49}]
        
    def __str__(self):
        return "Course ID: {}, Course Name: {}, Course Credit: {}".format(self.id, self.name, self.credit)
    
    def getCredit(self):
        return self.credit
    
    def setName(self, name):
        self.name = name
    
    def printDetail(self):
        print(self.__str__())

    def scoreGrading(self, score):
        for grade in self.grading:
            if grade["min"] <= score <= grade["max"]:
                return grade["Grade"]
        return "Invalid Score"
    
    def setGradeScheme(self, grading_scheme):
        # Check if the input grading_scheme has the correct format
        if isinstance(grading_scheme, list):
            for grade in grading_scheme:
                if isinstance(grade, dict) and all(key in grade for key in ["Grade", "min", "max"]):
                    continue
                else:
                    raise ValueError("Invalid grading_scheme format. Each grade should be a dictionary with 'Grade', 'min', and 'max' keys.")
        else:
            raise ValueError("Invalid grading_scheme format. It should be a list of grade dictionaries.")

        # If the input grading scheme is in the correct format, update the course's grading scheme
        self.grading = grading_scheme
    

class Enrollment(persistent.Persistent):
    def __init__(self, course, score, student):
        self.course = course
        self.score = score
        self.student = student
        
    def __str__(self):
        return "Course: {}, Grade: {}".format(self.course, self.grade, self.student)
    
    def getCourse(self):
        return self.course
    
    def getGrade(self):
        return self.course.scoreGrading(self.score)
        
    def printDetail(self):
        print(self.__str__())

    def getScore(self):
        return self.score
    
    def setScore(self, score):
        self.score = score

class Student(persistent.Persistent):
    def __init__(self, enrolls, id, name):
        self.enrolls = enrolls
        self.id = id
        self.name = name
        
    def __str__(self):
        courses = ""
        courses += "Transcripts\n"
        courses += "Student ID: {}\t Student Name: {}\n".format(self.id, self.name)
        for enroll in self.enrolls:
            courses += "Course: {}, Credit: {}, Score: {}, Grade: {}\n".format(enroll.getCourse().name, enroll.getCourse().credit,enroll.getScore(), enroll.getGrade())
        courses += "GPA: {:.3}".format(self.getGPA())
        return courses
        
    def getGPA(self):
        totalpoint = 0
        totalcredit = 0
        for enroll in self.enrolls:
            totalpoint += convert_grade(enroll.getGrade()) * enroll.getCourse().getCredit()
            totalcredit += enroll.getCourse().getCredit()
        return totalpoint / totalcredit
    
    def enrollCourse(self, course):
        enrollobj = Enrollment(course, None, self)
        self.enrolls.append(enrollobj)
        return enrollobj
    
    def getEnrollment(self, course):
        for enroll in self.enrolls:
            if enroll.getCourse() == course:
                return enroll
        return None
    
    def printTranscript(self):
        print(self.__str__())
    
    def setName(self, name):
        self.name = name