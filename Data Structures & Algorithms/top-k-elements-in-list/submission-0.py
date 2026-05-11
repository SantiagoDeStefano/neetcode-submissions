from typing import List
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dict = {}
        for num in nums:
           dict[num] = dict.get(num, 0) + 1

        bucket = [[] for _ in range(len(nums) + 1)]

        for num, count in dict.items():
           bucket[count].append(num)

        print(bucket)
        result = []

        for count in range(len(bucket) - 1, 0, -1):
           for num in bucket[count]:
              result.append(num)

              if len(result) == k:
                 return result