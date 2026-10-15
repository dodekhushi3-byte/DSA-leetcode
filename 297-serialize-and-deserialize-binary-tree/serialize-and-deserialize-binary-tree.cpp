/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        queue<TreeNode*> q;
        string s = "";

        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                s += "#,";
            } else {
                s += to_string(temp->val) + ",";

                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        stringstream ss(data);
        string val;

        getline(ss, val, ',');

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!getline(ss, val, ',')) break;

            if (val != "#") {
                curr->left = new TreeNode(stoi(val));
                q.push(curr->left);
            }

            if (!getline(ss, val, ',')) break;

            if (val != "#") {
                curr->right = new TreeNode(stoi(val));
                q.push(curr->right);
            }
        }

        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));