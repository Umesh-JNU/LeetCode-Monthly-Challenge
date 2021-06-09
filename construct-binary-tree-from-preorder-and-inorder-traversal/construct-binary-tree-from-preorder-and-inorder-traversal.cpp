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
    TreeNode *dfs(vector<int> inorder, vector<int> preorder, int ps, int pe, int is, int ie)
    {
        if(is > ie)
            return NULL;

        TreeNode *root = new TreeNode(preorder[ps]);
        int idx;
        for (int i = is; i <= ie; i++){
            if(inorder[i]==root->val){
                idx = i;
                break;
            }
        }

        // pe-ps = ie-is
        // pe = ps+ie-is
        // now all should correspond to left part
        // pe = (ps+1)+(pos-1)-(is) = ps+pos-is

        // left subtree = is -> idx-1
        // right subtree = idx + 1 -> ie
        // preorder left = ps + 1 -> ps + (idx - is)
        // preorder right = ps + (idx - is) + 1 -> pe

        root->left = dfs(inorder, preorder, ps + 1, ps + (idx-is), is, idx - 1);
        root->right = dfs(inorder, preorder, ps + (idx-is) + 1, pe, idx + 1, ie);

        return root;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        if (n == 0)
            return NULL;

        return dfs(inorder, preorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};