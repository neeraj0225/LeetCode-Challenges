class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p,q);
        p=p/g;
        q=q/g;
        if(p%2 ==0){
            return 2;
        }
        return q%2;
    }
};
