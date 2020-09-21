class Solution {
public:
    vector<int> partitionLabels(string A) {
        unordered_map <char,int> mp;
        vector<int> v;
        int n=A.size();
        if(n==0)
            return v;
        else if(n==1)
        {
            v.push_back(1);
            return v;
        }
        int prev_end=-1,i,j,temp_end,l;
        for(i=0;i<n;i++)
            mp[A[i]]=i;
        temp_end=-1;
        i=-1;
        while(i<n-1)
        {
            i++;
            j = mp[A[i]];
            if(j>temp_end)
                temp_end = j;
            if(i==temp_end)
            {
                v.push_back(i-prev_end);
                prev_end=i;
                temp_end = -1;
            }
        }
        mp.clear();
        return v;
    }
};