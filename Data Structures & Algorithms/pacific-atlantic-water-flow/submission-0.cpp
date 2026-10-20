class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;
        vector<vector<int>> results;

        int rows = height.size();
        int cols = height[0].size();

        for(int i = 0; i < rows; i++) {
            dfs(i, 0, pacific, height, height[i][0]);
            dfs(i, cols - 1, atlantic, height, height[i][cols-1]);
        }

        for(int j = 0; j < cols; j++) {
            dfs(0, j, pacific, height, height[0][j]);
            dfs(rows - 1, j, atlantic, height, height[rows-1][j]);
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(atlantic.count({i, j}) && pacific.count({i, j})) {
                    results.push_back({i, j});
                }
            }
        }
        return results;
    }

    void dfs(int row, int col, set<pair<int, int>>& visited, vector<vector<int>>& height, int prevHeight) {
        if(row < 0 || row >= height.size() || col < 0 || col >= height[0].size() || visited.count({row, col}) || height[row][col] < prevHeight) {
            return;
        }
        visited.insert({row, col});
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto direct : directions) {
            int newRow = row + direct.first;
            int newCol = col + direct.second;
            dfs(newRow, newCol, visited, height, height[row][col]);
        }
    }
};
