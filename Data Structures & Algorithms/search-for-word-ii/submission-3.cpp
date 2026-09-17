struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;

        isEnd = false;
    }
};

class Solution {
public:
    void buildTrie(TrieNode* root, vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            
            TrieNode *current = root;

            for(auto c : words[i]) {
                int index = c - 'a';

                if(current->children[index] == nullptr) {
                    current->children[index] = new TrieNode();
                }
                current = current->children[index];
            }
            current->isEnd = true;
        }
    }

    void dfs_diagram(
            int row, 
            int col, 
            vector<vector<char>>& board, 
            TrieNode *node, 
            vector<string>& results, 
            string currentWord
        ) {
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return;
        }
        if(board[row][col] == '#') {
            return;
        }
        int index = board[row][col] - 'a';        
        if(node->children[index] == nullptr) {
            return;
        }
        currentWord += board[row][col];
        if(node->children[index]->isEnd == true) {
            results.push_back(currentWord);
            node->children[index]->isEnd = false;
        }

        char temp = board[row][col];
        board[row][col] = '#';
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto direct : directions) {
            int newRow = row + direct.first;
            int newCol = col + direct.second;
            dfs_diagram(newRow, newCol, board, node->children[index], results, currentWord);
        }
        board[row][col] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        buildTrie(root, words);
        vector<string> results;
        string currentWord = "";
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                dfs_diagram(
                    row,
                    col,
                    board,
                    root,
                    results,
                    currentWord
                );
            }
        }
        return results;
    }
};