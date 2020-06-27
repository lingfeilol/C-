class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //由于是求最小的正整数，即一个数组里，未出现的最小整数，范围为1~数组长度。即在原来的数组里，利用位图，放到该存在的位置
        for(int i=0;i<nums.size();i++)
        {
            //换到该在的位置去
            while(0<nums[i] && nums[i]<=nums.size()&& nums[i]!=nums[nums[i]-1] )
            {
                swap(nums[i],nums[nums[i]-1]);//一直交换
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};