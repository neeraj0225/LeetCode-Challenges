class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& A, int k) {
        int count=0,prod=1,i,j,n=A.size();
        i=0,j=0;
        if(k<=1)
            return 0;
        for(i=0;i<n;i++)
        {
            prod *= A[i];
            while(prod >= k)
                prod /= A[j++];
            count += i-j+1;
        }
        return count;
    }
};
