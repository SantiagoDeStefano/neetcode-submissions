from typing import List

class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max_area = -1
        left_idx = 0
        right_idx = len(heights) - 1
        while left_idx < right_idx:
            current_area = (right_idx - left_idx) * min(heights[right_idx], heights[left_idx])
            max_area = max(max_area, current_area)
            if heights[left_idx] <= heights[right_idx]:
                left_idx += 1
            else:
                right_idx -= 1
        return max_area