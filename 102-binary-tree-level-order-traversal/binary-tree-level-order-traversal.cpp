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
    void dfs(TreeNode* node ,int level,vector<vector<int>>& ans){
        if(node==NULL) return;
        if(ans.size()==level){
            ans.push_back({});
        }
        ans[level].push_back(node->val);
        dfs(node->left,level+1,ans);
        dfs(node->right,level+1,ans);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(root,0,ans);
        return ans;
    }
};