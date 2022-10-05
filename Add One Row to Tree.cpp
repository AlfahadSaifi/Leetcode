



class Solution {
public:
    
    int k=0;
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* r=new TreeNode(val);
            r->left=root;
            root=r;
            return root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int len=q.size();
            k++;
            for(int i=0;i<len;i++){
                TreeNode*a=q.front();
                q.pop();
                if(k==depth-1){
                    TreeNode* node=new TreeNode(val);
                    node->left=a->left;node->right=NULL;
                    a->left=node;
                    
                    TreeNode* node1=new TreeNode(val);
                    node1->right=a->right;node1->left=NULL;
                    a->right=node1;   
                }
                else{
                    if(a->left)
                    q.push(a->left);
                    if(a->right)
                    q.push(a->right);
                }
            }
        }
        return root;
    }
};