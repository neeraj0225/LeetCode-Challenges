/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMaxRob(TreeNode *root, unordered_map<TreeNode*,int> &mp)
    {
        if(!root)
            return 0;
        if(mp.count(root) > 0)
            return mp[root];
        int withoutRoot = getMaxRob(root->left,mp) + getMaxRob(root->right,mp);
        
        int withRoot = root->val;
        if(root->left!= NULL)
        {
            withRoot += getMaxRob((root->left)->left,mp);
            withRoot += getMaxRob((root->left)->right,mp); 
        }
        
        if(root->right!= NULL)
        {
            withRoot += getMaxRob((root->right)->right,mp);
            withRoot += getMaxRob((root->right)->left,mp); 
        }
        
        mp[root] = max(withRoot,withoutRoot);
        return mp[root];
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        return getMaxRob(root,mp);
    }
};
