class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int> &curr,int n,int k,int start)
    {
        if(n<0)
            return;
        if(n==0 && curr.size()==k)
        {
            res.push_back(curr);
            return;
        }
        for(int i = start;i<=9;i++)
        {
            curr.push_back(i);
            helper(res,curr,n-i,k,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k<=0 || n < 0)
            return res;
        vector<int> curr;
        helper(res,curr,n,k,1);
        return res;
    }
};