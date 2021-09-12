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
            ans = max(ans, level);

        utils(root->left, ans, level + 1);
        utils(root->right, ans, level + 1);
    }
    int maxDepth(TreeNode *root)
    {
        int ans = INT_MIN;
        utils(root, ans, 1);
        return ans==INT_MIN ? 0 : ans;
    }
};