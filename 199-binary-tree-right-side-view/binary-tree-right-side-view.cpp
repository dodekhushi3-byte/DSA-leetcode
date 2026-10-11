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
    void preorder(TreeNode* node, int level, vector<int>& result){
        if(node == NULL){
            return;
        }
        if(result.size() < level){
            result.push_back(node->val);
        }
        preorder(node->right,level + 1, result);
        preorder(node->left,level + 1, result);

        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return {};
        }
       preorder(root, 1, result);
       return result;
        //===================BFS================
        // if(root == NULL){
        //     return {};
        // }
        // queue<TreeNode*> Q;
        // TreeNode* node = root;
        // vector<int> view;
        // Q.push(node);
        // while(!Q.empty()){
        //     int n = Q.size();
        //     TreeNode* temp = NULL;
        //     while(n--){
        //        temp = Q.front();
        //        Q.pop();

        //        if(temp->left != NULL){
        //         Q.push(temp->left);
        //        }
        //        if(temp->right != NULL){
        //         Q.push(temp->right);
        //        }
        //     }
        //     view.push_back(temp->val);
        // }
        // return view;
    }
};