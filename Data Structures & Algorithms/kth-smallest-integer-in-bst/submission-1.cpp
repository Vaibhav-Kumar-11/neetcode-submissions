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
        int cnt = 0;
        int result = -1;
        inOrdTrav(root, cnt, result, k);
        return result;
    }

    void inOrdTrav(TreeNode* root, int& cnt, int& result, int k) {
        if (root == NULL || result != -1) return;

        inOrdTrav(root->left, cnt, result, k);
        cnt++;
        if (cnt == k) {
            result = root->val;
            return;
        }
        inOrdTrav(root->right, cnt, result, k);
    }
};