class Solution {
public:
    void numIslands_helper(int row, int col, vector<vector<char>>& grid) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '0';
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto direct : directions) {
            int newRow = row + direct.first;
            int newCol = col + direct.second;
            numIslands_helper(newRow, newCol, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    numIslands_helper(i, j, grid);
                }
            }
        }
        return count;
    }
};
