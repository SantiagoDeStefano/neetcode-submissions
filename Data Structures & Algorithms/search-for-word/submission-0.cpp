class Solution {
public:
    bool dfs_diagram(int index, int row, int col, vector<vector<char>>& board, string word) {
        if(index >= word.size()) {
            return true;
        }
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto direct : directions) {
            int newRow = row + direct.first;
            int newCol = col + direct.second;
            if(dfs_diagram(index + 1, newRow, newCol, board, word)) {
                return true;
            }
        }
        board[row][col] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(dfs_diagram(0, i, j, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
