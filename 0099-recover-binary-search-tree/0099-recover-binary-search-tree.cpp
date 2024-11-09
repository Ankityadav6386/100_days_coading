class Solution {
public:
    TreeNode* first= NULL;
    TreeNode* second= NULL;
    TreeNode* prev= new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp= first->val;
        first->val=second->val;
        second->val=temp;
        
    }
    void inorder(TreeNode* root){
        
       while(root){
        if(root->left){
            //find predecessor
            TreeNode* predecessor=root->left;
            while(predecessor->right && predecessor->right!=root){
                predecessor=predecessor->right;
            }
            // we get 2 cases here
            // case 1: visiting predecessor for the first time
            if(predecessor->right==NULL){
                // create link b/w predecessor and root
                predecessor->right=root;
                root=root->left;
            }
            // case 2: visiting pred for the sec time
            else{
                predecessor->right=NULL;
                
                // performing some task
                if(first==NULL && root->val< prev->val){
                        first= prev;
                }

                //finding sec dip
                if(first!=NULL && root->val< prev->val){
                     second=root;
                 }
                 prev=root;
                root=root->right;
            }
        }
        else{
                // performing some task

                if(first==NULL && root->val< prev->val){
                        first= prev;
                }

                //finding sec dip
                if(first!=NULL && root->val< prev->val){
                     second=root;
                 }
                 prev=root;            
                 root=root->right;
        }
       }
       return ;

    }
};