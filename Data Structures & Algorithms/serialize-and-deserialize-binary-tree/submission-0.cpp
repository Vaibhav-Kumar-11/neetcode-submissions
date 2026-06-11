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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL) s.append("#,");
            else s.append(to_string(curr->val)+',');
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if (data.size() == 0) return NULL;

    stringstream ss(data);
    string token;

    getline(ss, token, ',');
    TreeNode* root = new TreeNode(stoi(token));

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (getline(ss, token, ',')) {
            if (token != "#") {
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            }
        }

        // Right child
        if (getline(ss, token, ',')) {
            if (token != "#") {
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            }
        }
    }

    return root;
}
};
