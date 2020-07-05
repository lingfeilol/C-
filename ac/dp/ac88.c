class Solution {
public:
    bool isMatch(string s, string p) {
        int slen=s.size(),plen=p.size();
        vector<vector<bool>> dp(slen+1,vector<bool>(plen+1,false));
        dp[0][0]=true;//为空时，匹配
        //s为空时，p非空，则p必须全为*，才可以匹配空字符
        //p为空时，s非空，则全为false;
        for(int j=1;j<=plen;j++)
        {
            dp[0][j]=dp[0][j-1] && (p[j-1]=='*');
        }
        for(int i=1;i<=slen;i++)
        {
            for(int j=1;j<=plen;j++)
            {
                if(p[j-1]=='?' ||s[i-1]==p[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];//匹配多个字符和匹配空字符的并集
                }
            }
        }
        return dp[slen][plen];
    }
};