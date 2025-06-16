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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        vector<int> level;
        int flag = 0; // 1 for right to left and 0 for left to right;
        queue<TreeNode*> q;

        if(root == NULL) return res;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();

            if(temp != NULL){
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                level.push_back(temp->val);
            }

            if(temp == NULL){
                if(!q.empty()) q.push(NULL);
                if(flag){
                    reverse(level.begin(),level.end());
                }
                res.push_back(level);
                level.clear();
                flag = !flag;
            }
        }

        return res;

    }
};