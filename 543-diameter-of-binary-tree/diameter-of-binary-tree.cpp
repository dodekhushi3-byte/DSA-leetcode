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
    int diameter = 0;
    int height(TreeNode* root) {
        TreeNode* node = root;
        if (node == NULL)
            return 0;

        int leftsum = height(node->left);
        int rightsum = height(node->right);
        diameter = max(diameter, (leftsum + rightsum));

        return 1 + max(leftsum, rightsum);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return diameter;
    }
};