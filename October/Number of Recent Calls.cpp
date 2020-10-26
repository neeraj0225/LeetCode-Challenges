class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(v.size()==0){
            v.push_back(t-3000);
            v.push_back(t);
            return 1;
        }
        v.push_back(t);
        int ans = 1;
        for(int i = v.size()-2;i>=0;i--){
            if(v[i]>=t-3000) ans++;
            else break;
        }
        return ans;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
