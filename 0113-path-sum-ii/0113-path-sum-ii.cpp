class Solution {
public:
void solve(TreeNode* root, int targetSum, int &currsum, vector<int> &path, vector<vector<int>>&ans){
    if(root==NULL){
        return;
    }
if(root->left == NULL && root->right==NULL){
    path.push_back(root->val);
    currsum += root->val;
if(currsum == targetSum){
    ans.push_back(path);
}
path.pop_back();
currsum -= root->val;
return;
}
path.push_back(root->val);
currsum += root->val;
solve(root->left, targetSum, currsum, path, ans);
solve(root->right, targetSum, currsum, path, ans);
path.pop_back();
currsum -= root->val;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>>ans;
    int sum = 0;
    vector<int>temp;
    solve(root, targetSum, sum, temp, ans);
    return ans;    
    }
};