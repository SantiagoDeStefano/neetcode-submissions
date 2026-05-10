class Solution {
public:
    void islandsAndTreasure_helper(vector<vector<int>>& grid, int row, int col, int step) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1) {
            return;
        }
        if(grid[row][col] < step) {
            return;
        } 
        grid[row][col] = step;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto direc : directions) {
            int newRow = row + direc.first;
            int newCol = col + direc.second;
            islandsAndTreasure_helper(grid, newRow, newCol, step + 1);
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    islandsAndTreasure_helper(grid, i, j, 0);
                }
            }
        }
    }
};
