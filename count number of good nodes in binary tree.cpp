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
    int count=0;
    
    void findGood(TreeNode* root,int tempVal){
        if(root==NULL) return;
        if(root->val>=tempVal){
            count++;
            tempVal=root->val;
        }
        findGood(root->left,tempVal);
        findGood(root->right,tempVal);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        if(!root->left && !root->right) return 1;
        
        int tempVal=0; 
        count++;
        tempVal=root->val;
        
        if(root->left)
            findGood(root->left,tempVal);
        
        tempVal=root->val;
        if(root->right)
            findGood(root->right,tempVal);
        
        return count;
        
    }
};