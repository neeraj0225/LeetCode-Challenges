class Solution {
public:
    vector<vector<int>> ans;
    void helper(int x, vector<int>& cand, int target,vector<int>& seq){
        // if(x==cand.size()) return;
        if(target<0) return;
        if(target == 0){
            ans.push_back(seq);
            return;
        }
        else{
            for(int i=x;i<cand.size();i++){
                seq.push_back(cand[i]);
                helper(i,cand,target-cand[i],seq);
                seq.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> seq;
        helper(0,candidates,target,seq);
        return ans;
    }
};
