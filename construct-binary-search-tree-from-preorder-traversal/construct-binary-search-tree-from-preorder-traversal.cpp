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
    int idx = 0;
    TreeNode *utils(int min, int max, vector<int> preorder)
    {
        if (idx >= preorder.size() || preorder[idx] < min || preorder[idx] > max)
            return NULL;
        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = utils(min, root->val, preorder);
        root->right = utils(root->val, max, preorder);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int n = preorder.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return new TreeNode(preorder[0]);

        return utils(INT_MIN, INT_MAX, preorder);
    }
};