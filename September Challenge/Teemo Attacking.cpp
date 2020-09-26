class Solution {
public:
    int findPoisonedDuration(vector<int>& A, int D) {
        int i,j,k,n=A.size();
        if(!n)
        {
            return 0;
        }
        else if(n==1)
        {
            return D;
        }
        else
        {
            k=0;
            for(i=0;i<n;i++)
            {
                j = A[i]+D;
                if(i!=n-1)
                {
                    if(j<=A[i+1])
                    {
                        k+=D;        
                    }
                    else
                    {
                        k+=A[i+1]-A[i];
                    }
                }
                else
                {
                    k+=D;
                }
            }
            return k;
        }
    }
};
