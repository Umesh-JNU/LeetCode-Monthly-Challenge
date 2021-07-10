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
    vector<int> rightSideView(TreeNode* A) {
        if (!A)
            return {};

        queue<TreeNode *> q;
        q.push(A);
        q.push(NULL);
        vector<int> ans = {};
        TreeNode *cur;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();

            if (cur)
            {
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if (!q.empty() && q.front() == NULL)
            {
                q.push(NULL);
                q.pop();
                // cout << cur->val << endl;
                ans.push_back(cur->val);
            }
        }
        return ans;
    }
};