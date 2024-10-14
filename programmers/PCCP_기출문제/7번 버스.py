def func1(num):
  if 0 > num:
    return 0
  else:
    return num

def func3(station):
  num = 0
  for people in station:
    if people == "Off":
      num += 1
  return num

def func4(station):
  num = 0
  for people in station:
    if people == "On":
      num += 1
  return num

def solution(seat, passengers):
  num_passenger = 0
  for station in passengers:
    num_passenger += func4(station)  # 타는 승객 수를 더함
    num_passenger -= func3(station)  # 내리는 승객 수를 뺌
  answer = func1(seat - num_passenger)  # 남은 좌석 수 계산 및 음수일 경우 0으로 변환
  return answer
