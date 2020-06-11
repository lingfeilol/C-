class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ret;
        dfs(ret,S,0);
        return ret;
    }

    void dfs(vector<string>& ret,string S,int i )
    {
        if(i==S.size())
        {
            ret.push_back(S);
            return ;
        }
        if(isalpha(S[i]))//是字符的情况下，当前已遍历过的字符串全排列复制两份
        {
            S[i]^=32;
            dfs(ret,S,i+1); //一个转大写，一个转小写
            S[i]^=32;
            dfs(ret,S,i+1);
        }
        else 
        {
            dfs(ret,S,i+1);
        }    
    }
};