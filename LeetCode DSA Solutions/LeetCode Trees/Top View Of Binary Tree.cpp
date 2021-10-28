class Solution
{
    public:
    map<int,pair<int,int>> mp;
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void buildVerticalTraversal(Node *root,int key,int depth){
        if(!root)
            return;
        if(mp.find(key) == mp.end()){
            pair<int,int> temp;
            temp.first = (root->data);
            temp.second = depth;
            mp[key] = temp;
        }else {
            if(mp[key].second > depth){
                mp[key].first = root->data;
                mp[key].second = depth;
            }
        }
        buildVerticalTraversal(root->left,key-1,depth+1);
        buildVerticalTraversal(root->right,key+1,depth+1);
    }
    vector<int> topView(Node *root)
    {
        vector<int> result;
        //Your code here
        buildVerticalTraversal(root,0,1);   
        for(auto i : mp){
            // cout<<"Key ->  "<<i.first<<"  ";
            result.push_back(i.second.first);
        }
        return result;
    }

};
