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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if(!root->left && !root->right)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);

        TreeNode *cur;
        int ans = 0;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();

            if(cur){
                if(cur->left){
                    q.push(cur->left);
                    if(!cur->left->left && !cur->left->right)
                        ans += cur->left->val;
                }
                if(cur->right)
                    q.push(cur->right);
            }
            else{
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
        }
        return ans;
    }
};