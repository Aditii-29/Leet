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
    //Through recursion
    // private:
    // void dfs(TreeNode*node,int level,vector<vector<int>>&res){
    //     if(!node)return;
    //     if(level==res.size()){
    //         res.push_back({});
    //     }
    //     if(level % 2==0){
    //         res[level].push_back(node->val);
    //     }else{
    //     res[level].insert(res[level].begin(),node->val);

    //     }

    //     dfs(node->left,level+1,res);
    //     dfs(node->right,level+1,res);
    // }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // vector<vector<int>>res;
        // dfs(root,0,res);
        // return res;

        //Using queue
        vector<vector<int>>res;
        if(!root) return res;

        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;

        while(!q.empty()){
            int n=q.size();
            vector<int>level(n);

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=leftToRight?i:(n-1-i);
                level[index]=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            res.push_back(level);
            leftToRight=!leftToRight;
        }
        return res;

    }
};