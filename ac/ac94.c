/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //中序遍历的非递归遍历 ，自己模拟使用栈保存左子树，有右子树了，就去判断此右子树
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        Left_push(root);
    }
    void Left_push(TreeNode* node)
    {
        while(node)  //每个节点的左子树全部加入栈里
        {
            st.push(node);
            node=node->left;
        }
    }
    
    /** @return the next smallest number */
    int next() { //注意第一个便是最小值，即栈顶元素
        TreeNode* cur=st.top();
        st.pop();
        int ret=cur->val;
        if(cur->right)
        {
            Left_push(cur->right);
        }
        return ret;

    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */