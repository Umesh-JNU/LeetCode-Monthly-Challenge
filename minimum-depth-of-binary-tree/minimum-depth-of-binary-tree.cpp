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
    void utils(TreeNode *root, int &ans, int level){
        if(!root)
            return;
        
        if(!root->left && !root->right)
             ans = min(ans, level);

        utils(root->left, ans, level + 1);
        utils(root->right, ans, level + 1);
    }
    int minDepth(TreeNode *root)
    {
        int ans = INT_MAX;
        utils(root, ans, 1);
        return ans==INT_MAX ? 0 : ans;
    }
};