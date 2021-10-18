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
    bool isCousins(TreeNode* root, int x, int y) {
        // base case 
        if(root->val == x || root->val == y)
            return false;
        
        queue<TreeNode *> que;
        que.push(root);
        que.push(NULL);
        int x_l, y_l, x_p, y_p, level = 0;
        TreeNode* cur;
        while(!que.empty()){
            cur = que.front();
            que.pop();
            
            if(cur){
                if(cur->left){
                    que.push(cur->left);
                    if(cur->left->val == x){
                        x_p = cur->val;
                        x_l = level+1;
                    }
                    if(cur->left->val == y){
                        y_p = cur->val;
                        y_l = level+1;
                    }
                }
                if(cur->right){
                    que.push(cur->right);
                    if(cur->right->val == x){
                        x_p = cur->val;
                        x_l = level+1;
                    }
                    if(cur->right->val == y){
                        y_p = cur->val;
                        y_l = level+1;
                    }
                }
            }
            else{
                if(!que.empty())
                    que.push(NULL);
                level++;
            }
        }
        if(x_p != y_p && x_l == y_l)
            return true;
        return false;
    }
};