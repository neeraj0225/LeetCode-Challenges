bool comparator(const vector<int> &a,const vector<int> &b)
{
    if(a[0] < b[0])
        return true;
    return false;
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        int i,j,n=A.size();
        vector<vector<int>> ans;
        if(n <=1 )
            return A;
        sort(A.begin(),A.end(),comparator);
        ans.push_back(A.front());
        for(i=1;i<n;i++)
        {
            if(A[i][0] > ans.back()[1])
            {
                ans.push_back(A[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1],A[i][1]);
            }
        }
        return ans;
    }
};
