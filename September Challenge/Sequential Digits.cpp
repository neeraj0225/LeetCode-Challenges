class Solution {
public:
    int lo,hi;
    vector<int> res;
    void CalSeq(int num)
    {
        if(num > hi)
        {
            return;
        }
        else if(num >= lo)
        {
            res.push_back(num);
        }
        int prev = num%10;
        num *= 10;
        if(prev < 9)
            CalSeq(num+prev+1);
    }
    vector<int> sequentialDigits(int low, int high) {
        int i,j;
        lo = low;
        hi = high;
        if(low<10 || high > 1000000000)
            return res;
        for(i=1;i<=9;i++)
        {
            CalSeq(i);
        }
        sort(res.begin(),res.end());
        return res;
    }
};