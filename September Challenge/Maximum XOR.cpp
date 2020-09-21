class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size(),temp,mask=0,maxEle=0,j,i;
        for(i=31;i>=0;i--)
        {
            mask = mask | (1<<i);
            unordered_set<int> s;
            for(j=0;j<n;j++)
                s.insert(mask & nums[j]);
            
            temp = maxEle | (1<<i);
            for(auto it=s.begin();it!=s.end();it++)
            {
                if(s.find(temp ^ *it) != s.end())
                {
                    maxEle = temp;
                    break;
                }
            }
        }
        
        return maxEle;
    }
};