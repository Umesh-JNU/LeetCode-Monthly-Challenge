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
    int minCameraCover(TreeNode* root) {
        // when root is null
        if(!root) return 0;
        // when only root ie. single node
        if(!root->left && !root->right) return 1;
        // else root can be covered by it parents so no need to have camera at root
        cam = 0;
        mp[NULL]=true;
        dfs(root, NULL);
        
        return cam;
    }
    
    // to start from bottom up manner
    // we reach to the most bottom node
    void dfs(TreeNode* node, TreeNode* parent){
        if(node){
            dfs(node->left, node);
            dfs(node->right, node);
        
        // this is the when to add camera
        // if parent is null (ie root) and is not covered ie. (parent == NULL && !mp[node])
        // or 
        // any of its chile is not covered.
            if((parent == NULL && !mp[node]) || (!mp[node->left] || !mp[node->right])){
                cam++;
                mp[node]=true;
                mp[node->left]=true;
                mp[node->right]=true;
                mp[parent]=true;
            }
        }
    }
private:
    int cam;
    map<TreeNode*, bool> mp;
};