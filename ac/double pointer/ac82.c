class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //滑动窗口，里面维护一个0，就是说最多只有一个0，出现第二个了，就更新结果
        int ret=0;
        int zero=0;
        for(int i=0,j=0;i<nums.size();i++)
        {
            if(nums[i]==0) zero++;
            while(zero > 1) //出现两个0时
            {
                zero-=!nums[j++]; //减去之前的那个0;
            }
            ret=max(ret,i-j);
        }
        return ret;
    }
};