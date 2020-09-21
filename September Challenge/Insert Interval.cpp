class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& newInt) {
        int i,j,k,n;
        if(newInt.size() == 0)
            return A;
        vector<vector<int>> res;
        res.push_back(A[0]);
        n = A.size();
        j=0;
        while(j < n && A[j][1] < newInt[0])
        {
            res.push_back(A[j++]);
            
        }
        i=j;
        j=res.size()-1;
        for(;i<n;i++)
        {
            if(A[i][0] > res[j][1])
            {
                res.push_back(A[i]);
                j++;
            }
            else if(A[i][0] == res[j][1])
            {
                res[j][1] = A[i][1];
            }
            else
            {
                if(A[i][1] > res[j][1])
                {
                    res[j][1] = A[i][1];
                }
            }
        }
        return res;
    }
};