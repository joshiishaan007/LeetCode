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
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }

    pair<int,int> dfs(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        auto [leftDiameter, leftHeight] = dfs(root->left);
        auto [rightDiameter, rightHeight] = dfs(root->right);

        int diameter = max(max(leftDiameter, rightDiameter),leftHeight+rightHeight);

        return {diameter, max(leftHeight, rightHeight)+1};
    }
};