class Solution {
public:
    string convert(string s, int numRows) {
        int l = s.length();
        if(numRows == l || numRows == 1)
            return s;
        int distance = (2 * numRows) - 2;
        string result;
        for(int i=0;i<numRows;i++)
        {
            int varDistance = distance - 2 * i;
            for(int j = i; j<l; j+=distance){
                result.push_back(s[j]);
                if(varDistance > 0 && varDistance < distance && j + varDistance < l){
                    result.push_back(s[j + varDistance]);
                }
            }
        }
        return result;
    }
};
