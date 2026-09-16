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

class WordDictionary {
    TreeNode *root;

public:
    WordDictionary() {
        root = new TreeNode();    
    }
    
    void addWord(string word) {
        TreeNode *current = root;
        for(char c : word) {
            int index = c - 'a';

            if(current->children[index] == nullptr) {
                current->children[index] = new TreeNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }
    
    bool search_helper(TreeNode* node, string& word, int index) {
        if (index == word.size()) {
            return node->isEnd;
        }

        char c = word[index];

        if (c != '.') {
            int childIndex = c - 'a';

            if (node->children[childIndex] == nullptr) {
                return false;
            }

            return search_helper(node->children[childIndex], word, index + 1);
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                if (search_helper(node->children[i], word, index + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return search_helper(root, word, 0);
    }
};
