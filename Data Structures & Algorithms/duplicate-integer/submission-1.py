class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        duplicates: dict[int, int] = {}
        for num in nums:
            duplicates[num] = duplicates.get(num, 0) + 1
        
        for duplicate in duplicates:
            if duplicates[duplicate] >= 2:
                return True
            
        return False