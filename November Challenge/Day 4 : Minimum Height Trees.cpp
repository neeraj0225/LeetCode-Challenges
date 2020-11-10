class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int i,j;
        vector<int> leaves;
        unordered_map<int,unordered_set<int>> tree;
        unordered_map<int,int> degree;
        if(n==0)
        {
            return leaves;
        }
        else if(n==1)
        {
            leaves.push_back(0);
            return leaves;
        }
        else 
        {
            for(i=0;i<edges.size();i++)
            {
                tree[edges[i][0]].insert(edges[i][1]);
                tree[edges[i][1]].insert(edges[i][0]);
                degree[edges[i][0]]++;
                degree[edges[i][1]]++;
            }
            for(i=0;i<n;i++)
            {
                if(degree[i] == 1)
                    leaves.push_back(i);
            }
            vector<int> newLeaves;
            while(n > 2)
            {
                n = n - leaves.size();
                int size = leaves.size();
                newLeaves.clear();
                for(i=0;i<size;i++)
                {
                    int curr = leaves[i];
                    for(auto a : tree[curr])
                    {
                        tree[a].erase(curr);
                        degree[a]--;
                        if(degree[a] == 1)
                            newLeaves.push_back(a);
                    }
                }
                leaves = newLeaves;
            }
        }
        return leaves;
    }
};
