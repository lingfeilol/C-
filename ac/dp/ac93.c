class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         要使得最小的血量，那么我最终拯救完公主之后，我的血量维持到最低值1，那岂不是最划算的了。
// 而我已经知道了我在最后一格，扣完血的血量是1了，那么我自然就知道上一步扣完血之后的剩余血量了！
// 假如说最后一个扣5滴血，扣完之后是1，那么在上一次扣完血之后的剩余血量至少是6。
// 到这里，我们就不难想到我们可以用在某个位置上，扣完血之后的最低血量作为状态咯。
// 转移方程的话我们其实已经提到了，需要注意的是在每一个位置的最低值都不能小于等于0，只能是1。


        int m = dungeon.size(), n = dungeon[0].size();
        if(m == 0 || n == 0)
            return 0;
        // dp[i][j] 表示骑士在此位置所需要的最小生命值
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(i == m - 1 && j == n - 1)
                // 最右下角的位置
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                else if(i == m - 1)
                // 最下面的一行
                    dp[i][j] = max(1, dp[i][j + 1] - dungeon[i][j]);
                else if(j == n - 1)
                // 最右面的一列
                    dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
                else 
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
