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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            auto add=new TreeNode(v);
            add->left=root;
            return add;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        while(!q.empty())
        {
            depth++;
            //队列里存的是每一层的节点，只要到了指定层，就可以操作里面的节点
            if(depth==d-1)
            {
                while(!q.empty())
                {
                    auto cur=q.front();
                    q.pop();
                    auto addleft=new TreeNode(v);
                    auto addright=new TreeNode(v);
                    auto nextleft=cur->left;
                    auto nextright=cur->right;
                    cur->left=addleft;
                    addleft->left=nextleft;
                    cur->right=addright;
                    addright->right=nextright;
                }
                break;//加完后，跳出
            }
            //保存每一层的节点
            int size=q.size();
            for(int i=0;i<size;i++) 
            {
                auto cur=q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return root;
    }
};