class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        size = 26
        letters = set(letters)
        for i in range(1, size):
            next_ord = ord(target) + i
            letter = chr(next_ord if next_ord <= ord('z') else next_ord - size)
            if letter in letters:
                return letter

