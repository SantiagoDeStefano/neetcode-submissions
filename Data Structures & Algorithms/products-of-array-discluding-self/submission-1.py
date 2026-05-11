from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
      result = []

      prefix = [1] * (len(nums))
      for i in range(0, len(nums) - 1):
        prefix[i + 1] = prefix[i] * nums[i]

      postfix = [1] * (len(nums))
      for i in range(len(nums) - 2, -1, -1):
        postfix[i] = postfix[i + 1] * nums[i + 1]

      for i in range(0, len(nums)):
        result.append(prefix[i] * postfix[i])

      return result