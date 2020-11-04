class Solution {
public:
    int maxPower(string s) {
        int i,n,maxi=INT_MIN;
        unordered_map<char,int> mp;
        n = s.size();
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        else
        {
            i=1;
            char curr = s[0];
            mp[curr]++;
            int k=1;
            while(i < n)
            {
                if(s[i]==curr)
                {
                    k++;
                    if(mp[curr] < k)
                        mp[curr]=k;
                }
                else
                {
                    curr = s[i];
                    k=1;
                }
                i++;
            }
            for(auto j: mp)
            {
                if(j.second > maxi)
                    maxi = j.second;
            }
        }
        return maxi;
    }
};
