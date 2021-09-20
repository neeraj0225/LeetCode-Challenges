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
    bool findSubTree(TreeNode* r, TreeNode* s){
       if(!s || !r){
           return (!s && !r);
       }else if(r->val == s->val){
           return findSubTree(r->left,s->left) && findSubTree(r->right,s->right);
       }else{
           return false;
       }
        
    }
    bool isSubtree(TreeNode* r, TreeNode* s) {
        if(!r)
          return false;
         if(findSubTree(r,s))
             return true;
        return (isSubtree(r->left,s) || isSubtree(r->right,s));
    }
};
