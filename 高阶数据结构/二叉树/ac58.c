/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //也是先遍历左路节点，再回来访问右树
 //不同于前序，中序遍历时先左再根，再右。 所以要先把左路进栈，然后再访问栈顶
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> st;
        auto cur=root;
        while(cur || !st.empty())
        {
            //每一次都是先把左路全部进栈
            while(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            auto top=st.top();
            st.pop();
            ret.push_back(top->val);//访问节点
            cur=top->right;//判断右树
        }
        return ret;
    }
};