class Solution {
public:
    string removeZero(string str) 
    { 
        int n = str.size();
        if(n==1)
            return str;
        int i = 0; 
        while (n - i - 1 > 1 && str[i] == '0') 
           i++; 
        str.erase(0, i); 
        return str; 
    } 
    void separator(string s,vector<string> &v)
    {
        string str="";
        int i,n=s.size();
        for(i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                string pushi = removeZero(str);
                v.push_back(pushi);
                str.clear();
            }
            else
            {
                str+=s[i];    
            }
        }
        string pushi = removeZero(str);
        v.push_back(pushi);
        str.clear();
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1,v2;
        separator(version1,v1);
        separator(version2,v2);
        int i,j,n=v1.size(),m=v2.size();
        i=0;j=0;
        long long int k,l;
        while(i<n && j<m)
        {
            k = stoll(v1[i]);
            l = stoll(v2[j]);
            if(k > l)
            {
                return 1;
            }
            else if(k < l)
            {
                return -1;
            }
            i++;
            j++;
        }
        if(i<n)
        {
            
            while(i<n)
            {
                k = stoll(v1[i]);
                if(k>0)
                    return 1;
                i++;
            }
        }
        if(j<m)
        {
            while(j<m)
            {
                l = stoll(v2[j]);
                if(l > 0)
                    return -1;
                j++;
            }
        }
        return 0;
    }
};