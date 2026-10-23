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
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftsum = dfs(root->left);
        if(leftsum == -1) return -1;

        int rightsum = dfs(root->right);
        if(rightsum == -1) return -1;

        if(abs(leftsum - rightsum) > 1) return -1;
        return max(leftsum, rightsum) + 1;
    }
};