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
    int maxSum = INT_MIN;
    int maxPathSum_helper(TreeNode *root) {
        if(root == nullptr) {
            return 0;
        }
        
        int left_sum = max(0, maxPathSum_helper(root->left));
        int right_sum = max(0, maxPathSum_helper(root->right));
        
        maxSum = max(maxSum, left_sum + root->val + right_sum);

        return root->val + max(left_sum, right_sum);
    }
    int maxPathSum(TreeNode* root) {
        maxPathSum_helper(root);
        return maxSum;
    }
};
