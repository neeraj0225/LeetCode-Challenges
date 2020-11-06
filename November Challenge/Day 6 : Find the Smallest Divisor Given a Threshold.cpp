class Solution {
public:
    int DivisorSum(int div,vector<int> &A,int n)
    {
        int i,sum=0,r;
        for(i=0;i<n;i++)
        {
            r = A[i]/div;
            if(A[i]%div != 0)
            {
                r++;
            }
            sum+=r;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& A, int t) {
        int currBest = INT_MAX,n,mid=0,l,h;
        n = A.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,A[i]);
        }
        if(t > maxi)
        {    
            maxi = t;
        }
        l = 0; h = maxi;
        while(l < h)
        {
            mid = (l+h)/2;
            if(mid == 0)
            {
                currBest = 1;
                break;   
            }
            if(DivisorSum(mid,A,n) > t)
            {
                l = mid + 1;
            }
            else
            {
                if(currBest > mid)
                {
                    currBest = mid;
                }
                h = mid;
            }
        }
        return currBest;
    }
};
