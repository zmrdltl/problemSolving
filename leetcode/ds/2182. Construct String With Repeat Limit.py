from heapq import heappush, heappop
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        char_map = {}
        max_heap = []
        for c in s:
            char_map[c] = char_map.get(c,0) + 1
        char_map = sorted(char_map.items(), key=lambda x:x[0],reverse=True)

        for char, freq in char_map:
            heappush(max_heap,(-ord(char), freq))

        answer, prev = '', ''

        while max_heap:
            minus_ord, freq = heappop(max_heap)

            char = chr(-minus_ord)
            offset = 0

            if char == prev and freq + 1 > repeatLimit:
                offset = 1
            answer += char * (min(freq,repeatLimit)-offset)

            if not max_heap:
                break

            minus_ord2, freq2 = heappop(max_heap)
            char2 = chr(-minus_ord2)
            answer += char2

            if freq > repeatLimit - offset:
                heappush(max_heap, (minus_ord, freq - (repeatLimit - offset)))
            if freq2 - 1 > 0:
                heappush(max_heap, (minus_ord2, freq2 - 1))

            prev = char2

        return answer
