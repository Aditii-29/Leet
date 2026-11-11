class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        calculateMaxPath(root, res);
        return res;
    }

private:
    int calculateMaxPath(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }
        int leftSum = max(0, calculateMaxPath(root->left, res));
        int rightSum = max(0, calculateMaxPath(root->right, res));
        res = max(res, leftSum + rightSum + root->val);
        return max(leftSum, rightSum) + root->val;
    }
};