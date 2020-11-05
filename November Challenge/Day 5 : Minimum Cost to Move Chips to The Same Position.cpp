class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int i,s2=0,s1=0;
        int n = position.size();
        map<int,int> mp;
        for(i=0;i<n;i++)
        {
            mp[position[i]]++;
        }
        for(auto j : mp)
        {
            if(j.first == 1)
            {
                s1 = j.second;
                continue;
            }
            else if(j.first == 2)
            {
                s2 = j.second;
                continue;
            }
            else
            {
                if(j.first%2 == 0)
                {
                    s2+=j.second;
                }
                else
                {
                    s1+=j.second;
                }
            }
        }
        if(s1 < s2)
        {
            return s1;
        }
        else 
        {
            return s2;
        }
    }
};
