class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0));
        dp[0][0]=0;
        int ret=0;
    
        for(int i=1;i<=A.size();i++)
        {
            for(int j=1;j<=B.size();j++)
            {
                if(A[i-1]==B[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                ret=max(ret,dp[i][j]);
            }
        }
        return ret;

    }
};