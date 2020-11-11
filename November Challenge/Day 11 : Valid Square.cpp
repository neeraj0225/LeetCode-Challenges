#include<bits/stdc++.h>
bool comparator(const pair<int,int> &a,const pair<int,int> &b)
    {
        if(a.first < b.first)
            return true;
        else if(a.first == b.first)
        {
            if(a.second < b.second)
                return true;
        }
       return false;
    }
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        float dis1,dis2,diag1,diag2;
        vector<pair<int,int>> v;
        v.push_back({p1[0],p1[1]});
        v.push_back({p2[0],p2[1]});
        v.push_back({p3[0],p3[1]});
        v.push_back({p4[0],p4[1]});
        sort(v.begin(),v.end(),comparator);
        //Prove Isoceles triangle
        dis1 = sqrt(pow(v[0].first-v[1].first,2) + pow(v[0].second-v[1].second,2));
        // cout<<dis1<<endl;
        dis2 = sqrt(pow(v[2].first-v[0].first,2) + pow(v[2].second-v[0].second,2));
        // cout<<dis2<<endl;
        if(dis1!=dis2 || dis1 == 0 || dis2 == 0)
            return false;
        diag1 = (sqrt(pow(v[0].first-v[3].first,2) + pow(v[0].second-v[3].second,2)));
        // cout<<diag1<<endl;
        diag2 = (sqrt(pow(v[2].first-v[1].first,2) + pow(v[2].second-v[1].second,2)));
        // cout<<diag2<<endl;
        if(diag1 != diag2 || diag1==0 || diag2 == 0)
            return false;
        float sum = ceil(sqrt(pow(dis1,2)+pow(dis2,2)));
        diag1 = ceil(diag1);
        // cout<<sum<<endl;
        if(sum != diag1)
            return false;
        return true;
    }
};
