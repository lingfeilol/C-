class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int len = days.size();
        int n = days[len-1];
         vector<int> dp(n+1,0);
         for(int i=0;i<len;i++){
             dp[days[i]] = 0x3f3f3f3f;//标记一下要出门的那一天
         }
         for(int i=1;i<=n;i++){
            if(dp[i] == 0){ //不出门的不花钱
                dp[i] = dp[i-1];
            }else{//贪心的选择三种出门方式里的最小花费
                dp[i] = min({dp[i], dp[i-1] + costs[0], dp[max(0,i-7)] + costs[1], dp[max(0,i-30)] + costs[2] });
            }
         }
         return dp[n];
    }
};