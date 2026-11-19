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
void kthSmallest_helper(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    if(root == nullptr) {
        return;
    }
    minHeap.push(root->val);
    kthSmallest_helper(root->left, minHeap);
    kthSmallest_helper(root->right, minHeap);
}

int kthSmallest(TreeNode* root, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    kthSmallest_helper(root, minHeap);
    for(int i = 1; i < k; i++) {
        minHeap.pop();
    }
    return minHeap.top();
}
};
