class Solution {
public:
    vector<int> ret;
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.empty()|| nums.size()==1) return nums;
        // sort(nums.begin(),nums.end(),greater<int>());//降序排列先
        // int sum=0;
        // for(int x=0;x<nums.size();x++)
        // {
        //     sum+=nums[x];
        // }
        // int i=0;
        // int j=0;
        // int k=0;
        // int flag=0;
        // for( k=0;k<=nums.size();k++)//区间
        // {
        //     if(flag==1)
        //         break;
        //     //枚举每一种区间情况
        //     int tmp=0;
        //     i=0,j=i+k;//从最小区间开始，且数组降序排列了，所以一旦满足条件，及就是贪心的选择
        //     while(i<=j)
        //     {
        //         tmp+=nums[i++];
        //     }
        //     i=0;
        //     if(tmp>sum-tmp)
        //     {
        //         while(i<=j)
        //         {
        //             ret.push_back(nums[i]);
        //             i++;
        //         }
        //         flag=1;
        //     }
        // }
        // return ret;
        sort(nums.begin(),nums.end());
        int tmp=0;
        int sum=0;
        for(int x=0;x<nums.size();x++)
        {
            sum+=nums[x];
        }
        while(nums.size()>0)
        {
            ret.push_back(nums.back());
            tmp+=nums.back();  
            nums.pop_back();
            if(tmp>sum-tmp)
                break;
        }
         return ret;
        
    }
};