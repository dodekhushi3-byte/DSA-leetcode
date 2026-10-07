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
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftsum = height(root->left);
        int rightsum = height(root->right);

        return 1 + max(leftsum, rightsum);
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        TreeNode* node = root;
        int leftsum = height(node->left);
        int rightsum = height(node->right);

        int balance = abs(leftsum - rightsum);

        if (balance > 1) {
            return false;
        }
        return isBalanced(node->left) && isBalanced(node->right);
    }
};