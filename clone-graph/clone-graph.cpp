/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        vector<Node*> visit(101, NULL);
        Node *root = new Node(node->val);
        dfs(node, root, visit);
        
        return root;
    }
    
    void dfs(Node *u, Node *root, vector<Node*> &visit){
        visit[u->val] = root;
        for(auto v: u->neighbors){
            if(visit[v->val] == NULL){
                Node *temp = new Node(v->val);
                root->neighbors.push_back(temp);
                dfs(v, temp, visit);
            }
            else{
                root->neighbors.push_back(visit[v->val]);
            }
        }
    }
};
// 1 1
// --2
// 2 2
// --1
// --3
// 3 3
// --2
// --4
// 4 4
// --1
// --3
// --4
// 4 4
// --1
// --3
// 3 3
// --2
// 2 2
// --1
// --3
// --4
