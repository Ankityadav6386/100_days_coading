class Solution {
public:
    void computeInorder(TreeNode* root, int k, vector<int> &nums){
        if(!root)   return ;

        computeInorder(root->left,k,nums);
        nums.push_back(root->val);
        computeInorder(root->right,k,nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        computeInorder(root,k,nums);
        int l=0,h=nums.size()-1;
        while(l<h){
            if(nums[l]+nums[h]==k)  return true;
            else if(nums[l]+nums[h]<k)  l++;
            else h--;
        }
        return false;
    }
};