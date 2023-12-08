r, c = map(int, input().split())
n = int(input())

current_time = 0
robot_x, robot_y = 0, 0
arr = []
visited_locations = set()

for i in range(n):
    date, x, y = map(int, input().split())
    if (x, y) not in visited_locations:
        arr.append([date, x, y])
        visited_locations.add((x, y))

arr = sorted(arr, key=lambda x: x[0])

while len(arr) > 0:
    collected = False
    current_target = arr.pop(0)
    x = current_target[1]
    y = current_target[2]
    
    while not collected:
        if(current_target[0] > current_time):
            current_time += 1
            continue
        elif(current_target[0] <= current_time and x == robot_x and y == robot_y):
            collected = True
            break
        
        if x > robot_x:
            robot_x += 1
        elif x < robot_x :
            robot_x -= 1
        if y > robot_y:
            robot_y += 1
        elif y < robot_y:
            robot_y -= 1
        
        current_time += 1
    
    print(current_time, robot_x, robot_y)
        
