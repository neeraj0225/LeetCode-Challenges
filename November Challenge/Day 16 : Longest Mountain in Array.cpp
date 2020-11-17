class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i,j,res=0,count,flag,n=A.size();
        for(i=1;i<n;i++)
        {
            flag = 0;
            count = 1;
            j = i;
            while(j<n && A[j] > A[j-1])
            {
                count++;
                j++;
            }
            while(i!=j && j<n && A[j] < A[j-1])
            {
                count++;
                j++;
                flag=1;
            }
            if(i!=j && flag && count>2)
            {
                res = max(res,count);
                j--;
            }
            i = j;
        }
        return res;
    }
};
