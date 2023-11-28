x = [10,2,123,23]
x.sort()
print(x)
a = Rectangle(0,0,100,100)
b = Rectangle(50,60,75,75)

def intersect(self,rec):
        if (self.x >= rec.x) and  (rec.x + rec.width >= self.x) :
            newx = self.xcoor
            if (self.x + self.width) < (rec.x + rec.width):
                newrec.width = self.width
            else :
                newrec.width = rec.width - (self.x - rec.x) 

        if (rec.x >= self.x) and (self.x + self.width >= rec.x) :
            newx = rec.x
            if (self.x + self.width) > (rec.x + rec.width):
                newrec.width = rec.width
            else :
                newrec.width = self.width - (rec.x - self.x)


        if (self.y >= rec.y) and (self.y - rec.height <= rec.y) :
            newy = rec.y
            if (self.y - self.height) < (rec.y - rec.height):
                newrec.height = rec.height
            else : 
                newrec.height = self.height - (self.y - rec.y) 

        if (rec.y >= self.y) and (rec.y - rec.height <= self.y) :
            newy = self.y 
            if (self.y - self.height) > (rec.y - rec.height):
                newrec.height = self.height
            else : 
                newrec.height = rec.height - (rec.y - self.y) 
        return rectangle(newx,newy,newwidth,newheight)