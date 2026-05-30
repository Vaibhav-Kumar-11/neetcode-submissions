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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        inOrdTrav(root,temp);
        return temp[k-1];
    }

    void inOrdTrav(TreeNode* root, vector<int>& temp){
        if(root==NULL) return;

        inOrdTrav(root->left,temp);
        temp.push_back(root->val);
        inOrdTrav(root->right,temp);
    }
};
