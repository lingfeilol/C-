/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//非递归遍历，则按照递归的思路去推， 先根节点，在左子树，在考虑右子树
//即先 左路节点  再左路节点的右子树
//然后循环这一步，由于是非递归，则需要用栈来模拟

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> st;
        auto cur=root;
        while(cur||!st.empty()) //去右子树的节点访问完了，取栈顶元素继续迭代
        {
            //先访问左路节点   //前序遍历，访问节点时，先根节点，左节点，再右节点，而右节点需要判断才可以
            while(cur)
            {
                ret.push_back(cur->val);//访问操作
                st.push(cur);//入栈，之后判断右子树
                cur=cur->left;
            }
            auto top=st.top();//根和左都访问完了，就进右子树，要是为空，就在判断处取栈顶，相当于回到上一层（模拟递归）
            st.pop();
            cur=top->right;
        }
        return ret;
    }
};