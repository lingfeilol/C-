/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //也还是先遍历左树节点，再遍历右树。但是注意访问顺序变成 先左再右 再根
 //之前都是根据先访问完根节点，再去其的右树遍历。
 //而这里变成先遍历根节点，但是不访问，遍历时还要去其右树遍历。这样就把之前的访问关系打乱了，最后不知道该根节点的该不该访问，所以要对其访问右树做个标记，证明已完成其右树遍历，可以访问此跟了
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> st;
        auto cur=root;
        TreeNode* visited=NULL;
        while(cur|| !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            auto top=st.top();
            // 1、不断取栈中的节点，如果右树是空，或者上个访问的节点就是右树的根，
            //      这两种情况就  表示右树已经访问过了，便可以访问这个根节点了，并出栈。
            //2.否则就访问右子树:左路节点+右子树的子问题
            if(top->right==NULL || top->right==visited)//判断是否可以访问该根节点
            {
                ret.push_back(top->val);
                st.pop();
                visited=top;//标记一下
            }
            else
                cur=top->right;
        }
        return ret;
    }
};