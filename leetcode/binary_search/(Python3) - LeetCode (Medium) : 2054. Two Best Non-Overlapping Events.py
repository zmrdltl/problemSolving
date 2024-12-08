from bisect import bisect_left

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda x: x[1])
        max_values_until_current_event = [0]*len(events)
        max_values_until_current_event[0] = events[0][2]

        for i in range(1, len(events)):
            max_values_until_current_event[i] = max(max_values_until_current_event[i-1], events[i][2])
        max_sum = 0
        end_times = [event[1] for event in events]

        for i in range(len(events)):
            current_value = events[i][2]
            start_time = events[i][0]
            non_intersect_idx = bisect_left(end_times, start_time) - 1
            if non_intersect_idx >= 0:
                max_sum = max(max_sum,max_values_until_current_event[non_intersect_idx] + current_value)
            else:
                max_sum = max(max_sum, current_value )
        return max_sum