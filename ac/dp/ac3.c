class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int len =nums.size();
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int ret=0;
        for(auto e: dp)
        {
            ret=max(ret,e);
        }
        return ret;
    }
};