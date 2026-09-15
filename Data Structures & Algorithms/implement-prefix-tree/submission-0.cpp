struct TreeNode {
    TreeNode* children[26];
    bool isEnd;

    TreeNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class PrefixTree {
    TreeNode *root;

public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* current = root;
        for(char c : word) {
            int index = c - 'a';

            if(current->children[index] == nullptr) {
                current->children[index] = new TreeNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        TreeNode *current = root;
        for (char c : word) {
            int index = c - 'a';

            if(current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreeNode *current = root;
        for (char c : prefix) {
            int index = c - 'a';

            if(current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
};
