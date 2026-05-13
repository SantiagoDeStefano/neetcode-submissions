import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        if not s:
            return False

        s_cleaned = re.sub(r"[^A-Za-z0-9]", "", s).lower()

        left_pointer = 0
        right_pointer = len(s_cleaned) - 1

        while(left_pointer <= right_pointer):
            if s_cleaned[left_pointer] != s_cleaned[right_pointer]:
                return False

            left_pointer += 1
            right_pointer -= 1

        return True