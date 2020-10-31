bool comp(vector<int>& a, vector<int>& b){
    if(a[0]==b[0]) return a[1]>b[1];
    else return a[0]<b[0];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        int n = in.size();
        if(n<=1) return n;
        sort(in.begin(),in.end(),comp);
        int ans = 1;
        vector<int> curr = in[0];
        for(int i=0;i<n;i++){
            if(in[i][0]>=curr[0] && in[i][1]<=curr[1]){
                ;
            }
            else{
                ans++;
                curr = in[i];
            }
        }
        return ans;
    }
};
