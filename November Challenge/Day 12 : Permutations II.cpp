class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int i,n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        v.push_back(nums);
        i = next_permutation(nums.begin(),nums.end());
        while(i)
        {
            v.push_back(nums);
            i = next_permutation(nums.begin(),nums.end());
        }
        return v;
    }
};
