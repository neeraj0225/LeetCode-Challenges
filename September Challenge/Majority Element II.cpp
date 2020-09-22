class Solution {
public:
    vector<int> majorityElement(vector<int>& A) {
        int c1,c2,c1cnt=0,c2cnt=0,i,n=A.size();
        vector<int> res;
        if(!n)
            return res;
        else if(n == 1)
        {
            res.push_back(A[0]);
            return res;
        }     
        c1 = A[0];
        c2 = A[1];
        for(i=0;i<n;i++)
        {
            if(c1 == A[i])
                c1cnt++;
            else if(c2 == A[i])
                c2cnt++;
            else if(c1cnt == 0)
            {
                c1 = A[i];
                c1cnt = 1;
            }
            else if(c2cnt == 0)
            {
                c2 = A[i];
                c2cnt = 1;
            }
            else
            {
                c1cnt--;
                c2cnt--;
            }
        }
        c1cnt = 0;
        c2cnt = 0;
        for(i=0;i<n;i++)
        {
            if(A[i] == c1)
                c1cnt++;
            else if(A[i] == c2)
                c2cnt++;
        }
        if(c1cnt > n/3)
            res.push_back(c1);
        if(c2cnt > n/3)
            res.push_back(c2);
        return res;
    }
};
