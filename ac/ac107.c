class Solution {
public:
    vector<vector<string>> ret;
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        //先dp判断区间内是否回文
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                    dp[i][j]=true;
                else if( j-i==1)
                    dp[i][j] = s[i]==s[j];
                else 
                {
                    dp[i][j] = s[i]==s[j]&&dp[i+1][j-1];
                }
            }
        }
        vector<string> tmp;
        dfs(s,tmp,0,dp);
        return ret;
    }
    void dfs(string &s,vector<string>& tmp,int index,vector<vector<bool>>& dp)
    {
        if(index == s.size())
        {
            ret.push_back(tmp);
            return ;
        }
        for(int i=index;i<s.size();i++)
            if(dp[index][i])
            {
                tmp.push_back(s.substr(index,i-index+1));
                dfs(s,tmp,i+1,dp);
                tmp.pop_back();
            }
    }
};