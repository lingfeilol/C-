/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //树型dp问题，既然是dp那就要自下而上来找，返回最上面以根为入口来选择的最大金额
 //状态定义就是    当前位置往下的最大金额
 //而状态转移就是    1。要么选当前，但是儿子不能选 2.要么就是不选当前，可以选择儿子
 //而一个节点的状态就只有两种  当前 选first 和 不选second

//想要自下而上，就可以利用后序遍历，先找到儿子的状态，再选择当前的状态
class Solution {
public:
    pair<int,int>robHouse(TreeNode* node){
        if(!node)return make_pair(0,0);
        auto p1 = robHouse(node->left);
        auto p2 = robHouse(node->right);
        //第一位表示不抢劫该节点，其子节点可抢可不抢，取子节点的抢与不抢最大值。
        //第二位表示抢劫该节点，其子节点必须不抢。
        return make_pair(max(p1.first, p1.second) + max(p2.first, p2.second),
                        node->val + p1.first + p2.first);
    }

    int rob(TreeNode* root) {
        auto p = robHouse(root);
        return max(p.first,p.second);
    }
};
