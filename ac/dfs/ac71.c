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
    TreeNode* recoverFromPreorder(string s) {
        return dfs(s,0);
    }
    TreeNode* dfs(string& s,int lev)
    {
        int len=0;
        while(s[len]=='-') len++;
        if(len!=lev) return NULL;
        string sub;
        while(s[len]!='-'&& len<s.size()) sub+=s[len++];
        s=s.substr(len);
        auto node=new TreeNode(stoi(sub));
        node->left=dfs(s,lev+1);
        node->right=dfs(s,lev+1);
        return node;
    }
};