class Solution {
public:
    int rob(vector<int>& A) {
        int i,j,mxtillnow = INT_MIN,n=A.size();
        vector<int> v(n);
        if(n==0)
            return 0;
        else if(n==1)
            return A[0];
        else if(n==2)
            return max(A[0],A[1]);
        else
        {
            v[0]=A[0];
            v[1]=A[1];
            j=0;
            mxtillnow = v[0];
            for(i=2;i<n;i++)
            {
                v[i] = A[i]+mxtillnow;
                j++;
                mxtillnow = max(mxtillnow,v[j]);
            }
            for(;j<n;j++)
            {
                mxtillnow = max(mxtillnow,v[j]);
            }
        }
        return mxtillnow;
    }
};