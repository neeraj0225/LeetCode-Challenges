class Solution {
public:
    
    void dfs(string s,string d,unordered_set<string> &visited,map<string,vector<pair<string,double>>>         &mp,double &ans,double k)
    {
        if(visited.find(s)!=visited.end())
            return;
        else
        {
            visited.insert(s);
            if(s==d)
            {
                ans=k;
                return;
            }
            for(auto a:mp[s])
            {
                
                dfs(a.first,d,visited,mp,ans,k*a.second);
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& E, vector<double>& B, vector<vector<string>>& Q) {
        vector<double> v;
        int i,n=E.size();
        map<string,vector<pair<string,double>>> mp;
        for(i=0;i<n;i++)
        {
            mp[E[i][0]].push_back({E[i][1],B[i]});
            mp[E[i][1]].push_back({E[i][0],1/B[i]});
        }
        n=Q.size();
        for(i=0;i<n;i++)
        {
            double k=1.0;
            double ans=-1.0;
            unordered_set<string> visited;
            string s = Q[i][0];
            string d = Q[i][1];
            if(mp.find(s)==mp.end() || mp.find(d)==mp.end())
                v.push_back(-1.0);
            else
            {
                dfs(s,d,visited,mp,ans,k);
                v.push_back(ans);

            }
        }
        return v;
        
    }
};
