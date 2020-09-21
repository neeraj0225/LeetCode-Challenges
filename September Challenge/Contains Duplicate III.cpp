#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
        int i,n=A.size(),flag=0;
        if(n==0 || k<=0 || t<0)
            return false;
        if(k<=n)
        {
            multiset<long long int> st(A.begin(),A.begin()+k);
            for(i=0;i<n;i++)
            {
                st.erase(st.find((long long int)A[i]));
                if(i+k < n)
                    st.insert((long long int)A[i+k]);
                if(st.find((long long int)((long long int)A[i]+(long long int)t))!=st.end() || st.find((long long int)((long long int)A[i]-(long long int)t))!=st.end())
                    return true;
                if(st.upper_bound((long long int)((long long int)A[i]+(long long int)t)) != st.upper_bound((long long int)((long long int)A[i]-(long long int)t)))
                    return true;
            }
        } 
        else
        {
             multiset<long long int> st(A.begin(),A.begin()+n);
            for(i=0;i<n;i++)
            {
                st.erase(st.find((long long int)A[i]));
                if(i+k < n)
                    st.insert((long long int)A[i+k]);
                if(st.find((long long int)((long long int)A[i]+(long long int)t))!=st.end() || st.find((long long int)((long long int)A[i]-(long long int)t))!=st.end())
                    return true;
                if(st.upper_bound((long long int)((long long int)A[i]+(long long int)t)) != st.upper_bound((long long int)((long long int)A[i]-(long long int)t)))
                    return true;
            }
        }
        
        return false;
    }
};