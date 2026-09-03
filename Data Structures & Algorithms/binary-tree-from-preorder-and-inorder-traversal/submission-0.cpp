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
    TreeNode* buildTree_helper(deque<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        int val = preorder.front();
        preorder.pop_front();
        auto it = find(inorder.begin(), inorder.end(), val);
        int idx = it - inorder.begin();

        TreeNode *root = new TreeNode(val);
        vector<int> left_inorder(inorder.begin(), inorder.begin() + idx);
        vector<int> right_inorder(inorder.begin() + idx + 1, inorder.end());

        root->left = buildTree_helper(preorder, left_inorder);
        root->right = buildTree_helper(preorder, right_inorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> preorderQueue(preorder.begin(), preorder.end());
        return buildTree_helper(preorderQueue, inorder);
    }
};
