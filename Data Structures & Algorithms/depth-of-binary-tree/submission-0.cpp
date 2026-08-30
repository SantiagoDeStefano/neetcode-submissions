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
    int maxDepth_helper(TreeNode *root) {
        if(root == nullptr) {
            return 0;
        }
        return max(maxDepth_helper(root->left), maxDepth_helper(root->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        return maxDepth_helper(root);
    }
};
