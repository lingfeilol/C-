class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> dp(size+1,0);
        int max=nums[0];
        dp[0]=nums[0];
        //每个状态就是当前0~i这个数组里的满足最大和的连续子数组
        for(int i=1;i<size;i++)//下一个状态是根据前一个状态决定的
        {
            if(dp[i-1]>0)//前一个大于零，加上才可能更大
            {
                dp[i]=dp[i-1]+nums[i];
            }
            else//小于零，加上只可能更小，所以不加
                dp[i]=nums[i];
            if(dp[i]>max)
                max=dp[i];
        }
        return max;
    }
};