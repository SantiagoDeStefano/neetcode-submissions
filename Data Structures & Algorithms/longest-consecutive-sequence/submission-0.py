from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
      if not nums:
        return 0
      nums.sort()

      longest = 1
      current = 1

      for i in range(0, len(nums) - 1):
        if nums[i] == nums[i + 1]:
          continue
        
        if nums[i] + 1 == nums[i + 1]:
          current += 1
        else:
          longest = max(longest, current)
          current = 1
      
      longest = max(longest, current)

      return longest