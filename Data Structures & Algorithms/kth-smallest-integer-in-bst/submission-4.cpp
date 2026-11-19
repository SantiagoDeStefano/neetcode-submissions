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
void kthSmallest_helper_inorder(TreeNode* root, int& k, int& result) {
    if(root == nullptr || k <= 0) {
        return;
    }
    kthSmallest_helper_inorder(root->left, k, result);
    k = k - 1;
    if(k == 0) {
        result = root->val;
    }
    kthSmallest_helper_inorder(root->right, k, result);
}


int kthSmallest(TreeNode* root, int k) {
    // priority_queue<int, vector<int>, greater<int>> minHeap;
    // kthSmallest_helper(root, minHeap);
    // for(int i = 1; i < k; i++) {
    //     minHeap.pop();
    // }
    // return minHeap.top();
    int result = -1;
    kthSmallest_helper_inorder(root, k, result);
    return result;
}
};
