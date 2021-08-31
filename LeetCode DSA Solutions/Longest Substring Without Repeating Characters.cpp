class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0,maxLength=-1;
        unordered_map<char,int> mp;
        for(end=0;end<s.length();end++){
            if(mp.find(s[end])!=mp.end()){
                start = max(mp[s[end]] + 1,start);
            }
            mp[s[end]] = end;
            int temp = end - start;
            maxLength = max(temp,maxLength);
        }
        return maxLength+1;
    }
};