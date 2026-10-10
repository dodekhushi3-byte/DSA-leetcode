/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        TreeNode* node = root;
        queue<TreeNode*> Q;
        vector<vector<int>> ans;

        bool flag = true;
        Q.push(node);
        while (!Q.empty()) {
            int n = Q.size();
            vector<int> level(n);
            for (int i = 0; i < n; i++) {
                TreeNode* temp = Q.front();
                Q.pop();

                int index = (flag) ? i : n - 1 - i;
                level[index] = temp->val;
                if (temp->left != NULL) {
                    Q.push(temp->left);
                }
                if (temp->right != NULL) {
                    Q.push(temp->right);
                }
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};