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
//  Morris Traversal : without recursion and space
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        while(root){
            if(root->left){
                TreeNode* left = root->left;
                TreeNode* temp = left;
                while(temp->right) temp = temp->right;
                temp->right = root->right; //main step of morris traversal
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};