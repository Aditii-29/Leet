class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        long long maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> que;
        que.push({root, 0});
        
        while (!que.empty()) {
            int currLvlSz = que.size();
            unsigned long long stIdx = que.front().second;
            unsigned long long endIdx = que.back().second;
            maxWidth = max(maxWidth, (long long)(endIdx - stIdx + 1));
            
            for (int i = 0; i < currLvlSz; i++) {
                auto currNode = que.front();
                que.pop();
                unsigned long long currIdx = currNode.second - stIdx;
                if (currNode.first->left) {
                    que.push({currNode.first->left, currIdx * 2 + 1});
                }
                if (currNode.first->right) {
                    que.push({currNode.first->right, currIdx * 2 + 2});
                }
            }
        }
        
        return maxWidth;
    }
};