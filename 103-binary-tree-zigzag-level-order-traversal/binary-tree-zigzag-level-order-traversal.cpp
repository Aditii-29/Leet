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
                vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int size = q.size();

            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            if (!leftToRight)
                reverse(level.begin(), level.end());

            ans.push_back(level);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};