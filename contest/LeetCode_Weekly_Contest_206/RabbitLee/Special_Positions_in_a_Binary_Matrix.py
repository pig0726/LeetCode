class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows, cols = len(mat), len(mat[0])
        row_list = [sum(row) for row in mat]
        col_list = []
        for j in range(cols):
            col_list.append(sum([row[j] for row in mat]))
        
        res = 0
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 1:
                    if row_list[i] == 1 and col_list[j] == 1:
                        res += 1
        return res

