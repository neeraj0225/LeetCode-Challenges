class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i,n=pattern.size();
        stringstream ss;
        vector<string> v;
        ss<<str;
        string word;
        while(ss>>word)
        {
            v.push_back(word);
        }
        if(pattern.size()!=v.size())
            return false;
        unordered_map<char,string> mp;
        unordered_set<string> s;
        for(i=0;i<n;i++)
        {
            if(mp.find(pattern[i]) == mp.end())
            {
                if(s.find(v[i]) == s.end())
                {
                    mp[pattern[i]]=v[i];    
                    s.insert(v[i]);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(mp[pattern[i]] != v[i])
                {
                    return false;
                }
            }
        }
        mp.clear();
        s.clear();
        return true;
    }
};