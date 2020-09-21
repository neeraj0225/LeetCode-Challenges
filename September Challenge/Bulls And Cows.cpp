class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0,i,j,k,n=secret.size(),m=guess.size();
        unordered_map<char,int> mp;
        for(i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
            }
            else
            {
                mp[secret[i]]++;
            }
        }
        for(i=0;i<m;i++)
        {
            if(secret[i]!=guess[i])
            {
                if(mp.find(guess[i])!=mp.end() && mp[guess[i]]>0)
                {
                    cows++;
                    mp[guess[i]]--;
                    if(mp[guess[i]]==0)
                        mp.erase(guess[i]);
                }
            }
        }
        string str;
        str+=to_string(bulls)+"A"+to_string(cows)+"B";
        return str;
    }
};