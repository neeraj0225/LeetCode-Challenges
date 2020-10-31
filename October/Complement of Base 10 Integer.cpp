class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int p2 = 1;
        int ans = 0;
        while(n){
            ans += (n%2)? 0:p2;
            n = n/2;
            p2 *=2;
        }
        return ans;
    }
};
