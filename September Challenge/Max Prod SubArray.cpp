class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxend=1,mnend=1,flag=0,maxprod=1,i=0,n=nums.size();
        if(n==1)
            return nums[0];
        mxend=nums[0];
        maxprod=nums[0];
        mnend=nums[0];
        for(i=1;i<n;i++)
        {
           int a = mxend*nums[i];
            int b = mnend*nums[i];
            mxend = max(max(a,b),nums[i]);
            mnend = min(min(a,b),nums[i]);
            maxprod=max(mxend,maxprod);
        }
            return maxprod;
        
    }
};