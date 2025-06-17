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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> res;

        // if(!root){
        //     return res;
        // }

        q.push({root,{0,0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode* tempNode = temp.first;
            int x = temp.second.first, y = temp.second.second;

            nodes[x][y].insert(tempNode->val);

            if(tempNode->left) q.push({tempNode->left,{x-1,y+1}});
            if(tempNode->right) q.push({tempNode->right,{x+1,y+1}});
        }

        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};