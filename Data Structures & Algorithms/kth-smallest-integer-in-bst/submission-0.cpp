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
    int kthSmallest_helper(TreeNode* root, int k, int& count) {
        if(root == nullptr) {
            return 10001;
        }
        
        int left = kthSmallest_helper(root->left, k, count);
        if(left != 10001) {
            return left;
        }
        count++;

        if(count == k) {
            return root->val;
        }

        return kthSmallest_helper(root->right, k, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return kthSmallest_helper(root, k, count);
    }
};
