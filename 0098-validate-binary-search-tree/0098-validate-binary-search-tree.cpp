class Solution {
public:
bool solve(TreeNode* root, long long int lb, long long int ub){
    if(root==NULL)
    return true;   

if((root->val > lb && root->val < ub) && solve(root->left, lb, root->val) && solve(root->right, root->val, ub)){
    return true;
}
else{
    return false;
}
}

bool isValidBST(TreeNode* root) {
 long long int lowerBond = -4294967296;
 long long int upperBond =  4294967296;
 bool ans = solve(root, lowerBond,  upperBond);
 return ans;
    }
};