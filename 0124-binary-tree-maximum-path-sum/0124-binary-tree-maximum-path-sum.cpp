class Solution {
public:
    int maxi = INT_MIN;
    int sum(TreeNode* root){
        if(!root) return 0;
        int lsum=0, rsum=0;
        lsum = max(0, sum(root->left));
        rsum = max(0, sum(root->right));

        maxi = max(maxi, lsum + rsum + root->val);
        return root->val + max(lsum,rsum);                      
    }

    int maxPathSum(TreeNode* root) {
        int ans = sum(root);
        return maxi;
    }
};