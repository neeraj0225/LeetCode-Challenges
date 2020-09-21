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
    long long int BinaryToDecimal(vector<int> &v)
    {
        long long int i,r,k=0,a=0,n = v.size();
        i = n-1;
        while(i>=0)
        {
            k+=(long long int)((long long int)v[i]*pow(2,a));
            i--;
            a++;
        }
        return k;
    }
    void inorder(TreeNode *root,vector<int> &v,vector<long long int> &res)
    {
        if(!root)
            return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            long long int getNum = BinaryToDecimal(v);
            res.push_back(getNum);
            return;
        }
        inorder(root->left,v,res);
        if(root->left!=NULL)
            v.pop_back();
        inorder(root->right,v,res);
        if(root->right!=NULL)
            v.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        long long int sum=0;
        vector<long long int> res;
        vector<int> v;
        inorder(root,v,res);
        for(int i=0;i<res.size();i++)
        {
            sum+=res[i];
        }
        return sum;
    }
};