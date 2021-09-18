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
    TreeNode *prev = NULL;
    int count=1;
    int maxCount=INT_MIN;
    void generateModes(TreeNode* root,vector<int> &result){
        if(root->left)
            generateModes(root->left,result);
        if(prev){
            if(prev->val == root->val){
                count++;
            }else {
                count = 1;
            }
        }
        if(count > maxCount){
            result.clear();
            result.push_back(root->val);
            maxCount = count;
        } else if(count == maxCount){
            result.push_back(root->val);
        }
        prev = root;
        if(root->right)
            generateModes(root->right,result);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        generateModes(root,result);
        return result;
    }
};