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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> temp;

        if(root == NULL){
            return res;
        }

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node != NULL){
                temp.push_back(node->val);
            }

            if(node != NULL && node->left){
                q.push(node->left);
            }

            if(node != NULL && node->right){
                q.push(node->right);
            }

            if(node == NULL){
                res.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }
        }
        return res;
    }
};