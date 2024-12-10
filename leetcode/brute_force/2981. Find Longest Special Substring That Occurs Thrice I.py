class Solution:
    def maximumLength(self, s: str) -> int:
        def special(s:str) -> bool:
            for i in range(1, len(s)):
                if s[i] != s[i-1]:
                    return False
            return True
            
        sub_str_map = {}
        for i in range(0, len(s)):
            for j in range(i+1, len(s)+1):
                sub_str = s[i:j]
                if special(sub_str):
                    sub_str_map[sub_str] = sub_str_map.get(sub_str, 0) + 1

        max_length = -1
        for sub_str, occurred in sub_str_map.items():
            if occurred >= 3:
                max_length = max(max_length, len(sub_str))
        
        return max_length
        