class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int i,j,n;
        n = s.size();
        vector<int> dp(n+1);
        dp[n]=1;
        unordered_set<string> st;
        for(string &word : wordDict)
            st.insert(word);
        for(i=n-1;i>=0;i--)
        {
            string word;
            for(j=i;j<n;j++)
            {
                word.push_back(s[j]);
                if(st.find(word)!=st.end())
                {
                    if(dp[j+1])
                        dp[i]=1;
                }
            }
        }
        return dp[0];
    }
};
