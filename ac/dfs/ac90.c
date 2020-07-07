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
   vector<vector<int>> ret;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<int> tmp;
        dfs_ref(root,tmp,0,sum);
        return ret;
    }
    void dfs_copy(TreeNode* root,vector<int> tmp,int n,int sum)//传参用拷贝
    {
        if(!root)
            return ;
        tmp.push_back(root->val);//先加进去，由于是copy的临时变量数组，每一次递归进去都是拷贝的，回来时也都是之前的状态，即不需要回溯

        if(!root->left && !root->right)
        {
            if(n+root->val==sum)
            {
                ret.push_back(tmp);
                return ;
            }
        }
        dfs_copy(root->left,tmp,n+ root->val,sum);
        dfs_copy(root->right,tmp,n+ root->val,sum);
    }
    void dfs_ref(TreeNode* root,vector<int>& tmp,int n,int sum)//传参用引用
    {
        if(!root) return ;

        tmp.push_back(root->val);//由于是引用，每一次递归下去都是同一块内存的数组，返回时的状态是已经改变了的，需要返回时回溯

        if(!root->left && !root->right)
        {
            if(n+root->val==sum)
            {
                ret.push_back(tmp);
                return ;
            }
        }
        if(root->left)
        {
            dfs_ref(root->left,tmp,n+root->val,sum);
            tmp.pop_back();
        }
        if(root->right)
        {
            dfs_ref(root->right,tmp,n+root->val,sum);
            tmp.pop_back();
        }
    }
};