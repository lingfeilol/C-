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
public:
    string tree2str(TreeNode* t) {
        string ret;
        dfs(t,ret);
        return ret;
    }
    void dfs(TreeNode* root,string& ret)
    {
        if(!root)
            return ;
        ret+=to_string(root->val);
        if(root->left)
        {
            ret+='(';
            dfs(root->left,ret);
            ret+=')';
        }
        if(root->right)
        {
            if(!root->left)
            {
                ret+="()";
            }
            ret+='(';
            dfs(root->right,ret);
            ret+=')';
        }
    }
};