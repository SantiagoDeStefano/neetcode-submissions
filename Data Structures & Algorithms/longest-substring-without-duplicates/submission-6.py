class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 0:
            return 0

        seen = set()        
        left_idx = 0
        longest = 1

        for right_idx in range(0, len(s)):
            while s[right_idx] in seen:
                seen.remove(s[left_idx])
                left_idx += 1

            seen.add(s[right_idx])
            longest = max(longest, right_idx - left_idx + 1)
        return longest
