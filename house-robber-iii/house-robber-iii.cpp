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
    int utils(TreeNode*root, unordered_map<TreeNode *, int> &dp){
        if(!root)
            return 0;

        if(dp[root])
            return dp[root];

        int total = 0;
        if(root->left)
            total += utils(root->left->left, dp) + utils(root->left->right, dp);
        if(root->right)
            total += utils(root->right->right, dp) + utils(root->right->left, dp);

        return dp[root] = max(total + root->val, utils(root->left, dp) + utils(root->right, dp));
    }
    int rob(TreeNode *root)
    {
        if(!root)
            return 0;

        unordered_map<TreeNode *, int> dp;
        return max(utils(root, dp), utils(root->left, dp) + utils(root->right, dp));
    }
};