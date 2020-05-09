class Solution {
public:
//因为可以当天卖出再买入，所以可以简化为只要今天比昨天大就可以卖出
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                ans+=prices[i]-prices[i-1];
        }
        return ans;
    }
};