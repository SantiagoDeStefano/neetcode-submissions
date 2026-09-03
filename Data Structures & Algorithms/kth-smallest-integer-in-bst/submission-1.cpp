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
    void kthSmallest_helper(TreeNode* root, vector<int>& count) {
        if(root->left != nullptr) {
            kthSmallest_helper(root->left, count);
        }
        if(root != nullptr) {
            count.push_back(root->val);
        }
        if(root->right != nullptr) {
            kthSmallest_helper(root->right, count);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        kthSmallest_helper(root, result);
        return result[k-1];
    }
};
