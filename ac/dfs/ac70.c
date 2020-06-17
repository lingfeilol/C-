/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        preorder(root,ret);
        return ret;
    }
    void preorder(TreeNode* root,string& ret)
    {
        if(!root)
        {
            ret+="null,";
            return ;
        }
        ret+=to_string(root->val)+",";
        preorder(root->left,ret);
        preorder(root->right,ret);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string word;
        queue<string> q;
        while(getline(ss,word,','))
            q.push(word);
        return _deser(q);
    }
    TreeNode* _deser(queue<string>& q)
    {
        string tmp=q.front();
        q.pop();
        if(tmp=="null")
            return nullptr;
        TreeNode* node=new TreeNode(stoi(tmp));
        node->left=_deser(q);
        node->right=_deser(q);
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));