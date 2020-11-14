class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int period = minutesToTest/minutesToDie;
            return ceil(log10(buckets)/log10(period+1));
    }
};
