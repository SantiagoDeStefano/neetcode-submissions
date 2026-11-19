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
bool isValidBST_helper(TreeNode* root, int min, int max) {
    if(root == nullptr) {
        return true;
    }
    if(root->val <= min || root->val >= max) {
        return false;
    }
    return isValidBST_helper(root->left, min, root->val) && isValidBST_helper(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
    int min = -1000000000;
    int max = 1000000000;
    return isValidBST_helper(root, min, max);
}

};
