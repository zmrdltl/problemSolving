class Solution:
  def canBeValid(self, s: str, locked: str) -> bool:
    n = len(s)
    if n % 2 == 1:
      return False

    low, high = 0, 0

    # 왼쪽에서 오른쪽으로 확인
    for i in range(n):
      if locked[i] == '1':  # 변경 불가능
        if s[i] == '(':
          low += 1
          high += 1
        else:
          low -= 1
          high -= 1
      else:  # 변경 가능
        low -= 1  # 최악의 경우 모두 ')'로 취급
        high += 1  # 최선의 경우 모두 '('로 취급

      if high < 0:  # ')'가 너무 많아서 균형 불가능
        return False
      low = max(low, 0)  # low는 음수가 되지 않도록 보정

    low, high = 0, 0

    # 오른쪽에서 왼쪽으로 확인
    for i in range(n - 1, -1, -1):
      if locked[i] == '1':  # 변경 불가능
        if s[i] == ')':
          low += 1
          high += 1
        else:
          low -= 1
          high -= 1
      else:  # 변경 가능
        low -= 1  # 최악의 경우 모두 '('로 취급
        high += 1  # 최선의 경우 모두 ')'로 취급

      if high < 0:  # '('가 너무 많아서 균형 불가능
        return False
      low = max(low, 0)  # low는 음수가 되지 않도록 보정

    return True
