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
    void findRangeSum(TreeNode* root, int low, int high)
    {
        if(!root)
            return;
        if(root->val >= low && root->val <= high)
            result += root->val;
        if(root->val <= low)
        {
            findRangeSum(root->right,low,high);
        }
        else if(root->val >= high)
        {
            findRangeSum(root->left,low,high);
        }
        else
        {
            findRangeSum(root->left,low,high);
            findRangeSum(root->right,low,high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        findRangeSum(root,low,high);
        return result;
    }
};
