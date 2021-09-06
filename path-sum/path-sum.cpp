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
    bool trackPath(TreeNode *root, int targetSum){
        if(!root->left && !root->right){
            if(targetSum == root->val)
                return true;
            return false;
        }

        bool l = false, r = false;
        if(root->left)
            l = trackPath(root->left, targetSum - root->val);
        if(root->right)
            r = trackPath(root->right, targetSum - root->val);

        return l || r;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if(!root)
            return false;
        return trackPath(root, targetSum);
    }
};