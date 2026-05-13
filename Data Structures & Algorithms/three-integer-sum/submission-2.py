from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        
        for left_pointer in range(0, len(nums)):
            if left_pointer > 0 and nums[left_pointer] == nums[left_pointer - 1]:
                continue  # skip duplicate left

            middle_pointer = left_pointer + 1
            right_pointer = len(nums) - 1

            while middle_pointer < right_pointer:
                current_total = nums[left_pointer] + nums[middle_pointer] + nums[right_pointer]
                if current_total < 0:
                    middle_pointer += 1
                elif current_total > 0:
                    right_pointer -= 1
                else:
                    result.append([nums[left_pointer], nums[middle_pointer], nums[right_pointer]])
                    while middle_pointer < right_pointer and nums[middle_pointer] == nums[middle_pointer + 1]:
                        middle_pointer += 1
                    while middle_pointer < right_pointer and nums[right_pointer] == nums[right_pointer - 1]:
                        right_pointer -= 1

                    middle_pointer += 1
                    right_pointer -= 1

        return result