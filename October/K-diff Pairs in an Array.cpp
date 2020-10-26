class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        unordered_map<int, int> m;
        int ans=0;
        for(int x:nums){
            m[x]++;
        }
        for(auto p:m){
            int n = p.first;
            if((k==0 && m[n]>1) || (k!=0 && m.find(n-k)!=m.end())) ans++;
            // if((k==0 && m[n]>1) || (k!=0 && m[n-k])) ans++;
        }
        return ans;
    }
};
