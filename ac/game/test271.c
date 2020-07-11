class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for(int i=0;i<n;i++)
        {
            int sums=0;
            for(int j=i;j<n;j++)
            {
                sums+=nums[j];
                sum.push_back(sums);
            }
        }
        sort(sum.begin(),sum.end());
        cout<<endl;
        int ret=0;
        left-=1;
        right-=1;
        int mid=1000000000+7;
        while(left<=right)
        {
            ret+=sum[left++]%mid;
        }
        return ret; 
    }
};