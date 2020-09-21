class Solution {
public:
    bool isRobotBounded(string instructions) {
        unordered_map<char,pair<char,char>> mp{{'N',{'W','E'}},{'S',{'E','W'}},{'W',{'S','N'}},{'E',{'N','S'}}};
        
        unordered_map<char,pair<int,int>> dist{{'N',{0,1}},{'S',{0,-1}},{'E',{1,0}},{'W',{-1,0}}};
        int x=0,y=0;
        char facing = 'N';
        for(char ch : instructions)
        {
            if(ch == 'L')
            {
                facing = mp[facing].first;
            }
            else if(ch == 'R')
            {
                facing= mp[facing].second;
            }
            else if(ch == 'G')
            {
                x += dist[facing].first;
                y += dist[facing].second;
            }
        }
        if((x == 0 && y==0) || (facing != 'N'))
            return true;
        return false;
    }
};