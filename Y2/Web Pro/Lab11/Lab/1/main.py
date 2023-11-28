import ZODB, ZODB.FileStorage
import persistent
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
root.students[1101] = Student([], 1101, "Mr. John Doe")
root.students[1101].enrolls = [Enrollment(root.courses[101], 75, root.students[1101]), Enrollment(root.courses[201], 81, root.students[1101]), Enrollment(root.courses[202], 81, root.students[1101]), Enrollment(root.courses[301], 57, root.students[1101])]


root.students[1102] = Student([], 1102, "Mr. Zhong Li")
root.students[1102].enrolls = [Enrollment(root.courses[101], 65, root.students[1102]), Enrollment(root.courses[201], 86, root.students[1102]), Enrollment(root.courses[202], 73, root.students[1102])]


root.students[1103] = Student([], 1103, "Mr. Dvalinn Durinson")
root.students[1103].enrolls = [Enrollment(root.courses[101], 51, root.students[1103]), Enrollment(root.courses[201], 72, root.students[1103]), Enrollment(root.courses[202], 98, root.students[1103]), Enrollment(root.courses[301], 45, root.students[1103])]


transaction.commit()
db.close()