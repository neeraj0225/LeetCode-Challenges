class Solution {
public:
    int maxProfit(vector<int>& A) {
        int prevMax,i,j,n=A.size();
        if(n == 1 || n == 0)
            return 0;
        else
        {
            vector<int> v(n);
            v[n-1]=-1;
            prevMax = A[n-1];
            for(i=n-2;i>=0;i--)
            {
                if(A[i]>prevMax)
                {
                    v[i]=-1;
                }
                else
                {
                    v[i]=prevMax;
                }
                prevMax = max(A[i],prevMax);
                
                                   
            }   
          prevMax=0;
            for(i=0;i<n;i++)
            {
              if(v[i]!=-1)
              {
                    prevMax = max(prevMax,v[i]-A[i]);      
              }
            }
        }
        return prevMax;
    }
};