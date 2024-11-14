import sys
input = sys.stdin.readline

def find_time(child, attractions, ride_times):
    if child <= attractions:
        return child
    left, right = 0, 2000000000 * 30
    last_time = 0
    while left <= right:
        mid = (left + right) // 2
        passenger = attractions
        for time in ride_times:
            passenger += mid // time
        if passenger >= child:
            last_time = mid
            right = mid - 1
        else:
            left = mid + 1
    passenger = attractions
    for time in ride_times:
        passenger += (last_time - 1) // time
    for i, time in enumerate(ride_times):
        if last_time % time == 0:
            passenger += 1
        if passenger == child:
            return i + 1
    return -1
     
child, attractions = map(int, input().split())
ride_times = list(map(int, input().split()))

print(find_time(child, attractions, ride_times))