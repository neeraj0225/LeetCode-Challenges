class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        int i,j,n=A.size();
        vector<vector<int>> ans;
        if(!n)
            return ans;
        sort(A.begin(),A.end());
        ans.push_back(A[0]);
        if(n==1)
            return ans;
        for(i=1;i<n;i++)
        {
            if(A[i][0] <= ans[ans.size()-1][1])
            {
                if(A[i][1] >= ans[ans.size()-1][1])
                {
                    ans[ans.size()-1][1] = A[i][1];
                }
            }
            else
            {
                ans.push_back(A[i]);
            }
        }
        return ans;
    }
};
