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
    int ans = 0;
    void inorder(TreeNode* root, int n){
        if(root->left)
            inorder(root->left, (n*10)+root->val);
        if(root->right)
            inorder(root->right, (n*10)+root->val);
        if(!root->left && !root->right)
            ans += (n*10)+root->val;

        return;
    }
    int sumNumbers(TreeNode* root) {
        inorder(root, 0);
        return ans;
    }
};