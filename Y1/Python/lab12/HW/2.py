import turtle
import math

turtle.pensize(1)
turtle.speed(0)

def RobotBattle():
    #robotList stores the list of robots in the battle
    robotList = []

    while True:
        #Clear the screen and draw the robots
        turtle.clear()
        for robot in robotList:
            robot.draw()

        #Display the status of each robot
        print("=== Robots ====")
        i=0
        for robot in robotList:
            print(i," : ")
            robot.displayStatus()
            i+=1
        print("===============")

        #Ask user which robot to command or to create a new robot
        choice = input("Enter which robot to order, 'c' to create new robot, 'q' to quit : ")
        if choice == "q":
            break
        elif choice == "c":
            print("Enter which type of robot to create ")
            robotType = input("'r' for Robot, 'm' for MedicBot, 's' for StrikerBot : ")
            if robotType == "r":
                newRobot = Robot()
            elif robotType == "m":
                newRobot = MedicBot()
            elif robotType == "s":
                newRobot = StrikerBot()
            robotList = robotList + [newRobot]
        else :
            n = int(choice)
            robotList[n].command(robotList)
        #Delete all the robots with health <= 0 from the list
        i=0
        for robot in robotList:
            if(robot.health <= 0):
                del robotList[i]
            i+=1

class Robot(object):
    def __init__(self):
        self.x = 0
        self.y = 0
        self.health = 100
        self.energy = 100

    def move(self,x,y):
        if self.energy > 0 :
            self.x = x
            self.y = y
            self.energy -= 10

    def draw(self):
        turtle.penup()
        turtle.goto(self.x,self.y)
        turtle.pendown()
        turtle.circle(40)

    def displayStatus(self):
        print("x=", self.x, "y=", self.y, "health=", self.health, "energy=", self.energy)

    def command(self, robotList):
        print("Possible actions: move")
        newX = int(input("Enter new x-coordinate: "))
        newY = int(input("Enter new y-coordinate: "))
        self.move(newX,newY)

class MedicBot(Robot):
    def heal(self,r):
        distance = math.sqrt(((r.x-self.x)**2)+((r.y-self.y)**2))
        if self.energy >= 20 and distance <= 10 and r != self :
            self.energy -= 20
            r.health += 10

    def draw(self):
        super().draw()
        turtle.left(90)
        turtle.penup()
        turtle.forward(15)
        turtle.left(90)
        turtle.forward(5)
        turtle.pendown()
        for i in range(4):
            turtle.right(90)
            turtle.forward(20)
            turtle.left(90)
            turtle.forward(20)
            turtle.right(90)
            turtle.forward(10)
        turtle.left(180)

    def command(self, robotList):
        print("Possible actions: move, heal")
        action = input("'m' for move, 'h' for heal :")
        if action == 'm':
            super().command(robotList)
        elif action == 'h':
            r = int(input("Enter robot No. (select itself = do not thing) : "))
            self.heal(robotList[r])

class StrikerBot(Robot):
    def __init__(self):
        super().__init__()
        self.missile = 5
    
    def strike(self,r):
        distance = math.sqrt(((r.x-self.x)**2)+((r.y-self.y)**2))
        if self.energy >= 20 and self.missile > 0 and distance <= 10 and r != self :
            self.energy -= 20
            self.missile -= 1
            r.health -= 50

    def draw(self):
        super().draw()
        turtle.left(90)
        turtle.penup()
        turtle.forward(15)
        turtle.left(45)
        turtle.pendown()
        for i in range(4):
            turtle.forward(30)
            turtle.right(90)
        turtle.right(135)

    def displayStatus(self):
        super().displayStatus()
        print("missile=", self.missile)

    def command(self, robotList):
        print("Possible actions: move, strike")
        action = input("'m' for move, 's' for strike :")
        if action == 'm':
            super().command(robotList)
        elif action == 's':
            r = int(input("Enter robot No. (select itself = do not thing) : "))
            self.strike(robotList[r])
        
RobotBattle()
