/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int ret=0;
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return ret;
        dfs(root,0,sum);
        if(root->left)
            pathSum(root->left,sum);
        if(root->right)
            pathSum(root->right,sum);
        return ret;   
    }
    void dfs(TreeNode* root,int n,int sum)
    {
        if(!root)
            return ;
        if(n+root->val==sum)
        {
            ret++;
            //return ; 不能返回回去，
        }
        if(root->left)
            dfs(root->left,n+root->val,sum);
        if(root->right)
            dfs(root->right,n+root->val,sum);
    }
};