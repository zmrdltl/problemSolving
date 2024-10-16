def solution(arr, intervals):
    arr1 = arr[intervals[0][0]:intervals[0][1]+1]
    arr2 = arr[intervals[1][0]:intervals[1][1]+1]
    arr1.extend(arr2)
    return arr1