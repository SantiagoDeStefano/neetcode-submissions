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
void levelOrder_helper(TreeNode* root, int level, map<int, vector<int>>& levelMap) {
    if(root == nullptr) {
        return;
    }
    levelMap[level].push_back(root->val);
    levelOrder_helper(root->left, level + 1, levelMap);
    levelOrder_helper(root->right, level + 1, levelMap);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> results;
    map<int, vector<int>> levelMap;
    levelOrder_helper(root, 1, levelMap);
    for(auto [key, value] : levelMap) {

        results.push_back(value);
    }
    return results;
}
};
