class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(p==root|| q==root)//当两个在同一颗子树上，先访问到的就是祖先
            return root;
        
        if(p->val<root->val&& q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(p->val>root->val&& q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        else//在两边
            return root;
    }
};