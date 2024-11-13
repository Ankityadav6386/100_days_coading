class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) 
        return {};

        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*> up;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->left){
                    up[t->left]=t;
                    q.push(t->left);
                }
                if(t->right)
                {
                    up[t->right]=t;
                    q.push(t->right);
                }
            }
        }

    
        
        unordered_map<TreeNode*,bool> vis;
        q.push(target);
        vis[target]=true;
        int distance=0;

        while(!q.empty())
        {if(distance==k) break;
            int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* t=q.front();q.pop();
            if(t->left && !vis[t->left])
            {
                q.push(t->left);
                vis[t->left]=true;
            }
            if(t->right && !vis[t->right])
            {
                q.push(t->right);
                vis[t->right]=true;
            }
            if(up[t] && !vis[up[t]])
            {
                q.push(up[t]);
                vis[up[t]]=true;
            }
        }
        distance++;
        }
        vector<int> res;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};