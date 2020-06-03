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
    int tmp=0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root;
    }
    void inorder(TreeNode* root)
    {
        if(!root)
            return ;
        inorder(root->right);
        root->val+=tmp;
        tmp=root->val;
        inorder(root->left);
    }
};