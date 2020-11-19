class Solution {
public:
    string decodeString(string s) {
        int i=0,j,k,n=s.length();
        stack<int> key;
        stack<string> ss;
        if(!n || n==1 || n==2 || n==3)
            return s;
        string num,res="";
        while(i < n)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                while(s[i] >= '0' && s[i] <= '9')
                {
                    num.push_back(s[i]);
                    i++;
                }
                j = stoi(num);
                key.push(j);
                num.clear();
            }
            else if(s[i] == '[')
            {
                ss.push(res);
                res="";
                i++;
            }
            else if(s[i] == ']')
            {
               string sb;
               if(!ss.empty())
               {
                   sb = ss.top();
                   ss.pop();
               }
                k = key.top();
                key.pop();
                for(j=0;j<k;j++)
                {
                    sb += res;
                }
                res = sb;
                i++;
            }
            else
            {
                res.push_back(s[i]);
                i++;
            }
        }
        return res;
    }
};
