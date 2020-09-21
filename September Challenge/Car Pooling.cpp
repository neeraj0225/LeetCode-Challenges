class Solution {
public:
    bool carPooling(vector<vector<int>>& trip, int capacity) {
        int i,n=trip.size();
        vector<int> prefix(1001);
        if(n==0)
            return true;
        for(i=0;i<n;i++)
        {
            prefix[trip[i][1]]+=trip[i][0];
            prefix[trip[i][2]]-=trip[i][0];
        }
        for(auto j : prefix)
        {
            capacity-=j;
            if(capacity < 0)
                return false;
        }
        return true;
    }
};