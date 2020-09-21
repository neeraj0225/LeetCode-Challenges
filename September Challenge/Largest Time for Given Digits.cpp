#include <bits/stdc++.h>
class Solution {
public:
    bool validTime(string &str)
    {
        if(str[0] > '2')
        { return false; }
        if(str[0] == '2')
        {
            if(str[1] >= '4')
                return false;
        }
        if(str[2] >= '6')
        {
            return false;
        }
        return true;
    }
    string largestTimeFromDigits(vector<int>& A) {
        string str;
        int flag=0,i,j,n=A.size();
        vector<string> v;
        sort(A.begin(),A.end());
        int a[4];
        for(i=0;i<4;i++)
            a[i]=A[i];
            
        do{
            string s;
            for(i=0;i<n;i++)
            {
                s+=to_string(a[i]);
            }
            if(validTime(s))
            {
                v.push_back(s);
            }
            
        }while(next_permutation(a,a+4));
    if(v.size()==0)
    {
        return "";
    }
    else
    {
        sort(v.begin(),v.end());
        n = v.size();
        str = v[n-1].substr(0,2)+":"+v[n-1].substr(2,3);
        return str;
    }
}
};