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
    int result=0;
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        calculateDiff(root,root->val,root->val);
        return result;
    }
    void calculateDiff(TreeNode* root,int currMin,int currMax)
    {
        if(!root)
            return;
        result = max(result,max(abs(root->val - currMin),abs(root->val - currMax)));
        currMin = min(root->val,currMin);
        currMax = max(root->val,currMax);
        calculateDiff(root->left,currMin,currMax);
        calculateDiff(root->right,currMin,currMax);
    }
};
