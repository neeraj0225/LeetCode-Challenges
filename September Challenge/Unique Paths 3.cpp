class Solution {
public:
    int TotalPaths=0;
    void dfs(vector<vector<int>>& grid,int i,int j,int totZero)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == -1 || grid[i][j] == 99 || (grid[i][j]==2 && totZero !=0))
        {
            return;
        }
        if(grid[i][j]==2 && totZero ==0)
            TotalPaths++;
        if(grid[i][j]==0)
            totZero--;
        
        int temp = grid[i][j];
        grid[i][j]=99;
        
        dfs(grid,i+1,j,totZero);
        dfs(grid,i-1,j,totZero);
        dfs(grid,i,j+1,totZero);
        dfs(grid,i,j-1,totZero);
        
        grid[i][j] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int totZero=0,i,j,n = grid.size(),m;
        if(n)
             m = grid[0].size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    totZero++;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j,totZero);
                }
            }
        }
        return TotalPaths;
    }
};