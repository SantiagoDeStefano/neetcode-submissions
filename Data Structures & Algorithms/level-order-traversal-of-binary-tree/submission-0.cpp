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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if (root == nullptr) {
            return result;
        }
        q.push(root);
        while(!q.empty()) {
            vector<int> levels;
            int queueSizes = q.size();
            for(int i = 0; i < queueSizes; i++) {
                TreeNode *current = q.front();
                q.pop();
                levels.push_back(current->val);
                if(current->left != nullptr) {
                    q.push(current->left);
                }
                if(current->right != nullptr) {
                    q.push(current->right);
                }
            }
            result.push_back(levels);
        }
        return result;
    }
};
