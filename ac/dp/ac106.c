class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(s.empty())
            return 0;
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        //区间dp
        int count=n;
        for(int k=2;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(k==2)
                {
                    dp[i][j]= s[i]==s[j];
                }
                else
                    dp[i][j]=dp[i+1][j-1]&& s[i]==s[j];
                if(dp[i][j])
                    count++;
            }
        }
        return count;
    }
};