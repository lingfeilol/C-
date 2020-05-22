class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());//排序
        int left=0,right=1,len=nums.size()-1;
        int ret=0;
        while(right<=len)
        {
            if(nums[right]-nums[left]>k)
            {
                left++;//由于是排序，多了就下次多减一点
            }
            else if(nums[right]-nums[left]<k)
            {
                right++;//少了，那就下次让跟大的数来减
            }
            else
            {
                left++;
                right++;
                ret++;
            }
            while(right<=len&& nums[right]==nums[right-1])  right++;//提前判断重复项
            while(left>0&& left<=len && nums[left]==nums[left-1]) left++;
            if(right<=left)//当区间内的差值全是大于的，就增长一位
                right=left+1;
        }
        return ret;
    }
};