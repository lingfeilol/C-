class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i=0,j=0;
        int ret=1e6;
        int sum=0;
        for(i=0;i<nums.size();i++)//双指针
        {
            sum+=nums[i];
            while(sum>=s && j<=i)
            {
                ret=min(ret,i-j+1);
                cout<<i<<"-"<<j<<' '<<ret<<endl;
                sum-=nums[j];
                j++;
            }
        }
        return ret==1e6 ? 0:ret;
    }
};