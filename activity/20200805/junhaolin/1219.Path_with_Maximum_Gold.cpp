class Solution {
public:
    vector<vector<int>> grid;
    int maxSum;
    int dx [4] = {-1,0,1,0}, dy [4] = {0,-1,0,1};
    
    int getMaximumGold(vector<vector<int>>& grid) {
        this->grid = grid;
        this->maxSum = 0;
        
        for (int i=0; i<grid.size(); i++) 
            for (int j=0; j<grid[0].size(); j++) 
                traverse(0, i, j);
        
        return maxSum;
    }
    
    void traverse(int sum, int x, int y) {
        if (grid[x][y] > 0) {
            int value = grid[x][y];
            sum += value;
            grid[x][y] = 0;
            
            maxSum = max(maxSum, sum);
            
            for (int i=0; i<4; i++) {
                int X = x+dx[i], Y = y+dy[i];
                if (0 <= X && X < grid.size() && 0 <= Y && Y < grid[0].size()) {
                    traverse(sum, X, Y);
                }
            }
            
            grid[x][y] = value;
        }
    }
};
