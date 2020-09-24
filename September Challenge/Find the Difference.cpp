class Solution {
public:
    char findTheDifference(string s, string t) {
        int i,n=s.size(),m=t.size();
        unordered_map<char,int> mp;
        for(i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        for(i=0;i<m;i++)
        {
             mp[t[i]]--;
             if(mp[t[i]] < 0)
             {
                 return t[i];
             }
        }
        return ' ';
    }
};
