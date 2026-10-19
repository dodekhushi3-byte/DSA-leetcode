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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int n = preorder.size();
        for (int i = 1; i < n; i++) {
            TreeNode* curr = root;
            while (true) {
                if (curr->val < preorder[i]) {
                    if (curr->right == NULL) {
                        curr->right = new TreeNode(preorder[i]);
                        break;
                    } else {
                        curr = curr->right;
                    }
                } else {
                    if (curr->left == NULL) {
                        curr->left = new TreeNode(preorder[i]);
                        break;
                    } else {
                        curr = curr->left;
                    }
                }
            }
        }
        return root;
    }
};