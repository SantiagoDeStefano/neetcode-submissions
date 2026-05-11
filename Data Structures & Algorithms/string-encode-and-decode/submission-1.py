class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for word in strs:
          encoded += f"{len(word)}#{word}"
        return encoded        

    def decode(self, s: str) -> List[str]:
        decoded: List[str] = []
        index = 0

        while index < len(s):
          sign = s.find("#", index)
          length = int(s[index:sign])
          index = sign + 1
          decoded.append(s[index:index + length])
          index += length

        return decoded