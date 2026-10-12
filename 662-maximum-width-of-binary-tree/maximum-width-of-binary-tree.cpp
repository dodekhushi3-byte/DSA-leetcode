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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root == NULL) {
            return 0;
        }
        long long maxwidth = 0;

        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();

            long long L = q.front().second;
            long long R = q.back().second;
            maxwidth = max(maxwidth, R - L + 1);

            while (n--) {
                TreeNode* temp = q.front().first;
                long long ind = q.front().second;
                q.pop();

                if (temp->left != NULL) {
                    q.push({temp->left, 2 * ind + 1});
                }

                if (temp->right != NULL) {
                    q.push({temp->right, 2 * ind + 2});
                }
            }
        }
        return (int)maxwidth;
    }
};