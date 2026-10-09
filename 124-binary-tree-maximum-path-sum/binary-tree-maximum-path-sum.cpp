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
    
    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        maxPath(root, maximum);
        return maximum;
        
    }
    int maxPath(TreeNode* root ,int& maximum){
       TreeNode* node = root;
        if(root == NULL){
            return 0;
        }

        int leftsum =  max(0 ,maxPath(node->left, maximum));
        int rightsum =  max(0, maxPath(node->right, maximum));

        maximum = max(maximum, node->val + leftsum + rightsum );

        return node->val + max(leftsum, rightsum);
    }
};