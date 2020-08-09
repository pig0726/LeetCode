from collections import Counter

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        tiles_count = dict(Counter(tiles))
        return self.num_of_sequences(tiles_count) - 1
        
    def num_of_sequences(self, tiles: dict) -> int:
        ans = 1
        for k, v in tiles.items():
            if v > 0:
                tiles[k] -= 1 
                ans += self.num_of_sequences(tiles)
                tiles[k] += 1 
        return ans

