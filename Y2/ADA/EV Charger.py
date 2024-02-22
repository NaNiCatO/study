#EV
def opt(destination, stations):
    if len(stations) < 1:
        return destination
    stations.append(destination)
    distance = [stations[i+1] - stations[i] for i in range(len(stations)-1)]
    max_distance = max(distance)
    start = 0
    while start < len(distance) - 1:
        if distance[start] + distance[start+1] < max_distance:
            distance[start] = distance[start] + distance.pop(start+1)
        else:
            start += 1
    return max_distance + len(stations) - len(distance)

des = int(input())
numbers = list(map(int, input().split()))
end = input()
print(opt(des, numbers))