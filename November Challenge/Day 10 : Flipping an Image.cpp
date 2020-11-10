class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int i,j,n=A.size();
        if(n == 0)
            return A;
        int m=A[0].size();
        for(i=0;i<n;i++)
        {
            reverse(A[i].begin(),A[i].end());
        }
        for(i=0;i<n;i++)
        {
            for(j = 0;j<m;j++)
            {
                if(A[i][j])
                    A[i][j] = 0;
                else
                    A[i][j] = 1;
            }
        }
        return A;
    }
    
};
