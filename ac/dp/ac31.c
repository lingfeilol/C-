class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0 ) return 0;
        int n=nums.size();
        int ret=nums[0];
        int dpmax[n];
        int dpmin[n];
        dpmax[0]=dpmin[0]=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>0)//当前值为正数
            {
                dpmax[i]=max(nums[i],dpmax[i-1]*nums[i]);
                dpmin[i]=min(nums[i],dpmin[i-1]*nums[i]);
            }
            else //为负数或者为零
            {
                dpmax[i]=max(nums[i],dpmin[i-1]*nums[i]);
                dpmin[i]=min(nums[i],dpmax[i-1]*nums[i]);
            }
            ret=max(dpmax[i],ret);
        }
        return ret;


    }
};