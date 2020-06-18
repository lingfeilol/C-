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
    int ret=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ret;
    }
    //后序遍历，树形dp，
     //路径，只能有一个起点和一个终点
     //尝试以任意节点作为根节点得出各自最大路径和，选择其中最大的max_sum返回给上层
    // 对每一个根节点来说，最大路径和的求法如下：
    //1.首先把树划分为左右子树，以左子树为例，每次只能选左子树的左右子树中的一条路径来走（否则就不是路径了），因此在递归函数中每次返回左右子树的较大值来递加；
    //2.递归完左右子树之后，max_sum记录左子树路径加和、右子树路径加和（左右子树事先与0比较，为负则事先归零相当于不再走这边）、以及根节点自身的值，作为最终返回值。

    //小结：导致这个题有点麻烦的原因是，整体加和的左中右结构固定，而路径下一步怎么选则无序，因此递归函数与主函数返回值不应相同。
    int dfs(TreeNode* root)
    {
        if(!root) 
            return 0;
        int left=max(0,dfs(root->left));
        int right=max(0,dfs(root->right));
        ret=max(ret,root->val+left+right);//保存答案
        return max(left,right)+ root->val;//左右子树只能走一条，最大值返回给上一层
    }
};