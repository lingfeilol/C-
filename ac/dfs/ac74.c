class Solution {
    vector<string> ret;
public:
//暴力枚举所有情况，在判断是否有效，
    vector<string> generateParenthesis(int n) {
        string tmp;
        dfs(tmp,2*n);
        return ret;
    }
    void dfs(string & tmp,int n)
    {
        if(tmp.size()==n)
        {
            if(valid(tmp))
                ret.push_back(tmp);
            return ;
        }
        tmp+='(';
        dfs(tmp,n);
        tmp.pop_back();
        tmp+=')';
        dfs(tmp,n);
        tmp.pop_back();
    }
    bool valid(string & tmp)
    {
        int count=0;
        for(auto c: tmp)
        {
            if(c=='(')
                count++;
            else
            {
                count--;
            }
            if(count<0)
                return false;
        }
        return count==0;
    }
};


//剪枝回溯
class Solution {
    vector<string> ret;
public:
    vector<string> generateParenthesis(int n) {
        string tmp;
        dfs(tmp,0,0,2*n);
        return ret;
    }
    void dfs(string& tmp,int left,int right,int num)
    {
        if(tmp.size()==num)
        {
            ret.push_back(tmp);
            return ;
        }
        if(left < num/2)
        {
            tmp+='(';
            dfs(tmp,left+1,right,num);
            tmp.pop_back();
        }
        if(right<left)
        {
            tmp+=')';
            dfs(tmp,left,right+1,num);
            tmp.pop_back();
        }
    }
};