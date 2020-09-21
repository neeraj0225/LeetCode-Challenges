class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i,j,k,n=s.size();
        if(n==1)
            return false;
        for(i=n/2;i>=1;i--)
        {
            if(n%i == 0)
            {
                k = n/i;
                string str = s.substr(0,i);
                string st = str;
                for(j=1;j<k;j++)
                {
                    st+=str;
                }
                if(st==s)
                    return true;
            }
        }
        return false;
    }
};