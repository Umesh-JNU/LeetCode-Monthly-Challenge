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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> que;
        que.push(root);
        que.push(NULL);
        vector<int> level;
        while (!que.empty())
        {
            TreeNode *cur = que.front();
            que.pop();

            if (cur)
            {
                // cout << "cur-> val " << cur->val << endl;
                level.push_back(cur->val);

                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            else
            {
                // cout << "heredfdf" << endl;
                if(!que.empty())
                    que.push(NULL);
                res.push_back(level);
                level.clear();        
            }
        }
        return res;
    }
};