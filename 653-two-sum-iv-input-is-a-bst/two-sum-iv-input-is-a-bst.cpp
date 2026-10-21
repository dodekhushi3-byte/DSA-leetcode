class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;

        return dfs(root, k, st);
    }

    bool dfs(TreeNode* root, int k, unordered_set<int>& st) {
        if (root == nullptr) {
            return false;
        }

        int target = k - root->val;

        if (st.find(target) != st.end()) {
            return true;
        }

        st.insert(root->val);

        return dfs(root->left, k, st) ||
               dfs(root->right, k, st);
    }
};