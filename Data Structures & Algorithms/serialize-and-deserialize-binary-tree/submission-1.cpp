/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    void serialize_helper(TreeNode* root, string& serialize) {
        if(root == nullptr) {
            serialize += "#,";
            return;
        }
        serialize += to_string(root->val) + ",";
        serialize_helper(root->left, serialize);
        serialize_helper(root->right, serialize);
    }
    string serialize(TreeNode* root) {
        string serialize = "";
        serialize_helper(root, serialize);
        return serialize;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize_helper(vector<string>& serialize, int& i) {
        if(serialize[i] == "#") {
            i++;
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(serialize[i]));
        i++;
        root->left = deserialize_helper(serialize, i);
        root->right = deserialize_helper(serialize, i);

        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string> serialize;
        string item;

        for (char c : data) {
            if (c == ',') {
                serialize.push_back(item);
                item.clear();
            } else {
                item += c;
            }
        }

        int i = 0;
        return deserialize_helper(serialize, i);
    }
};
