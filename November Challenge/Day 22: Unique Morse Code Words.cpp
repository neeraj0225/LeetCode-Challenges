class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string store[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int i,j,k,n=words.size();
        unordered_set<string> s;
        for(i=0;i<n;i++)
        {
            string str;
            for(j=0;j<words[i].size();j++)
            {
                k = words[i][j] - 'a';
                str += store[k];
            }
            s.insert(str);
        }
        n = s.size();
        return n;
    }
};
