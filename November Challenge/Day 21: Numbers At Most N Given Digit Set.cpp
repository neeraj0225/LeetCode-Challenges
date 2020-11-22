class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int m = digits.size();
        if(m)
           sort(digits.begin(),digits.end());
        int sum=0,i,j,k,r,q=n,count=0;
        vector<int> v;
        string num = to_string(n);
        count = num.size(); 
        {
            for(i=1;i<count;i++)
            {
                sum += pow(m,i);
            }
            i=0;
            while(i < count)
            {
                j=0;
                while(j < m && digits[j][0] < num[i])
                {
                    sum += pow(m,count-i-1);
                    j++;
                }
                if(j == m || digits[j][0] > num[i])
                    return sum;
                i++;
            }
        }
        sum++;
        return sum;
    }
};
