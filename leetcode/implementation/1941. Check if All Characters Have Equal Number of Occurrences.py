class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        alphabatFrequency = {}
        for char in s: 
            if alphabatFrequency.get(char) == None:
                alphabatFrequency[char] = 0
            else:
                alphabatFrequency[char] += 1
        frequencies = [val for val in alphabatFrequency.values()]
        for i in range(0, len(frequencies) - 1):
            if frequencies[i] != frequencies[i+1]: 
                return False;
        return True    
