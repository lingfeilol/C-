class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0||k==1) return 0;
        int sum=1,left=0,right=0;
        int count=0;
        for(int right=0;right<nums.size();right++)//右边界
        {
            sum*=nums[right];
            while(sum>=k)//判断左边界是否收缩
            {
                sum/=nums[left];
                left++;    
            }
            count+=right-left+1; //重点步骤，可以算出此区间中满足条件的子数组的个数 
        }
        return count;
    }
};