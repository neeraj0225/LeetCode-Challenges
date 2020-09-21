class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        int i=0;
        string word,str;
        while(ss>>word)
        {
            i++;
            str = word;
        }
        if(i==0)
            return 0;
        return str.size();
    }
};