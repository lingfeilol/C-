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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<vector<int>> tmp;//把每条路径先保存，再判断
        vector<int> v;
        dfs(root,tmp,v);
        int count=0;
        for(auto e:tmp)
        {
            if(ishuiwen(e))
                count++;
        }
        return count;
        
    }
    bool ishuiwen(vector<int>& tmp)//判断是否为回文。当奇数个数大于等于两个时，绝不可能为回文
    {
        vector<int> map(10,0);
        for(int i=0;i<tmp.size();i++)
        {
            map[tmp[i]]++;
        }
        int count=0;
        for(auto e:map)
        {
            if(e%2!=0)
                count++;
        }
        if(count>1)
            return false;
        return true;
        
    }
    void dfs(TreeNode* root,vector<vector<int>>& tmp,vector<int> v)
    {
        if(root==NULL)
        {   
            return ;
        } 
        v.push_back(root->val);
        if(!root->left&&!root->right)
        {
            tmp.push_back(v);
        }
        if(root->left)  
            dfs(root->left,tmp,v);
        if(root->right)
            dfs(root->right,tmp,v);
        v.pop_back();
    }
};