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
    int tilt=0;
    int returnTilt(TreeNode *root)
    {
        if(!root)
            return 0;
        int left = returnTilt(root->left);
        int right = returnTilt(root->right);
        tilt += abs(right - left);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        
        int j = returnTilt(root);
        return tilt;
    }
};
