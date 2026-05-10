class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        temp_t = t

        for char_s in s:
            found = False

            for char_t in temp_t:
                if char_s == char_t:
                    temp_t = temp_t.replace(char_t, "", 1)
                    found = True
                    break

            if not found:
                return False

        return temp_t == ""