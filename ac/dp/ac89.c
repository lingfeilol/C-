class Solution {
public:
    bool isMatch(string s, string p) {
        s=" "+s;//防止该案例：""\n"c*"
        p=" "+p;
        int m=s.size(),n=p.size();
        bool dp[m+1][n+1];
        memset(dp,false,(m+1)*(n+1));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                     //判断匹配多个还是匹配单个还是匹配空
                    if(s[i-1]!=p[j-2] && p[j-2]!='.')//*只能依赖与前一个字符，不等且不为'.'，则只能代表为0个
                        dp[i][j]=dp[i][j-2];
                    else{//相同，则* 就有匹配多个或者单个的可能 //或者p[j-2]=='.'的情况，与*可以配和
                        dp[i][j]=dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};