class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = NULL;

        while (curr != NULL || !st.empty()) {
            // Traverse to the leftmost node
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* peekNode = st.top();
                // If there is a right child and it hasn't been visited yet, go right
                if (peekNode->right != NULL && lastVisited != peekNode->right) {
                    curr = peekNode->right;
                } else {
                    // Otherwise, process the node, pop it, and mark it as visited
                    ans.push_back(peekNode->val);
                    lastVisited = st.top();
                    st.pop();
                }
            }
        }
        return ans;
    }
};