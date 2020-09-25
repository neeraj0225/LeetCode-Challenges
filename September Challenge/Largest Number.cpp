bool comparator(const string &a, const string &b)
    {
        string x = a+b;
        string y = b+a;
        return (x > y);
    }
class Solution {
public:
    
    string largestNumber(vector<int>& A) {
        int i,n = A.size();
        string res;
        if(n==0)
        {
            return "";
        }
        else if(n==1)
        {
            return to_string(A[0]);
        }
        else
        {
            vector<string> v;
            for(i=0;i<n;i++)
            {
                v.push_back(to_string(A[i]));
            }
            sort(v.begin(),v.end(),comparator);
            for(i=0;i<n;i++)
            {
                res+=v[i];
            }
            if(res[0]=='0' && res[1]=='0')
            {
                return "0";
            }
            return res;
        }
    }
};
