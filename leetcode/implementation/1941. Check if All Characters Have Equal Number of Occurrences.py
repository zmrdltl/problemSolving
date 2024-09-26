class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        alphabatFrequency = {}
        for char in s: 
            if alphabatFrequency.get(char) == None:
                alphabatFrequency[char] = 0
            else:
                alphabatFrequency[char] += 1
        a = [val for val in alphabatFrequency.values()]
        for i in range(0, len(a) - 1):
            if a[i] != a[i+1]: 
                return False;
        return True    
