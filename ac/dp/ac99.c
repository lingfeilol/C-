class Solution {
    //既然是一个圈了，说明第一个和最后一个相邻，不能同时偷
    //那就是可以不搜第一个，和不搜最后一个 ，取两种的最大值，转换成两个基本的打家劫舍问题，再取最大值
public:
    
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len=nums.size();
        if(len==1)
            return nums[0];

        vector<int> a1(len,0);
        vector<int> a2(len,0);
        
        for(int i=0;i<len-1;i++)
        {
            a1.push_back(nums[i]);
        }
        int retmax=subrob(a1);
        for(int i=1;i<len;i++)
        {
            a2.push_back(nums[i]);
        }
        retmax=max(retmax,subrob(a2));
        return retmax;

    }
     int subrob(vector<int>& nums)  //基本打家劫舍问题
    {
        if(nums.empty()) return 0;
        int len=nums.size();
        vector<int> dp(len+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=1;i<len;i++)
        {
            dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
        }
        return dp[len];
    }
};