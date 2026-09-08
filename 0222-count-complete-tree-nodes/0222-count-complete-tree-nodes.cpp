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
    int LeftHeight(TreeNode* root){
        int height=0;
        TreeNode* node=root;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }
    int  RightHeight(TreeNode* root){
        int height=0;
        TreeNode* node=root;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=LeftHeight(root);
        int rh=RightHeight(root);
        if(lh==rh) 
           return (1 <<lh)-1;
        return 1+ countNodes(root->left)+ countNodes(root->right);

    }
    
};