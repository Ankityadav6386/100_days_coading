class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
       priority_queue<int> pq;
       int n=grid.size(),m=grid[0].size();
        unordered_map<int,int> M;
       for(int i=0;i<n;i++)
       {
            for(int j=0;j<m;j++)
            {
                if(!M[grid[i][j]]){
                    pq.push(grid[i][j]);
                    M[grid[i][j]]=1;
                }
                
                for(int k=1;k<(max(n,m)+1)/2;k++)
                {
                    

                    if(i+2*k>=n || j+k>=m || j-k<0)
                        continue;

                    int ans=grid[i][j];
                    for(int z=1;z<=k;z++)
                    {
                        ans+=grid[i+z][j+z];
                        ans+=grid[i+z][j-z];
                    }
                    int ref=i+2*k;
                    ans+=grid[ref][j];
                    for(int z=1;z<k;z++)
                    {
                        ans+=grid[ref-z][j+z];
                        ans+=grid[ref-z][j-z];
                    }
                    if(!M[ans]){
                    pq.push(ans);
                    M[ans]=1;
                }
                }
            }     
       }  
       vector<int> ans;
       int c=0;
       while(c<3 && !pq.empty())
       {
            c++;
            ans.push_back(pq.top());
            pq.pop();
       }
        return ans;
    }
};