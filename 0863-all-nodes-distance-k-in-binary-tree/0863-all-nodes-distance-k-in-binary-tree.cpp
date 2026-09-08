/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void makeparent(TreeNode* root){
        if(root==nullptr) return;
        
        if(root->left){
            parent[root->left]=root;
            makeparent(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            makeparent(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeparent(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int distance=0;
        while(!q.empty()){
            int size=q.size();
            if(distance==k){
                vector<int> ans;
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                    
                }
                return ans;
            }
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(parent.count(node) && !visited.count(parent[node])){
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            distance++;
        }
        return {};
    }
};