class Solution {
    //归并分治
public:
    
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size(),0);
         return mergesort(nums,0,nums.size()-1,tmp);   
    }
    int mergesort(vector<int>& nums,int left,int right,vector<int>& tmp )
    {  
        if(left >= right)
            return 0;
        int mid=left+(right-left)/2;
        
        int ans=mergesort(nums,left,mid,tmp)+mergesort(nums,mid+1,right,tmp);//先划分
        //在合并
        int k=0;
        int i=left;//左半边
        int j=mid+1;//右半边
        while(i<=mid && j<=right)
        {
            if(nums[i]<=nums[j])
            {
                tmp[k++]=nums[i];
                i++;
            }
            else
            {
                ans+=(mid-i+1);//本来就是排好了序的，在区间内，后面的肯定也都是大于的，且是左闭右闭，所以加一
                tmp[k++]=nums[j];
                j++;
            }
        }
        while(i<=mid)
        {
            tmp[k++]=nums[i++];
        }
        while(j<=right)
            tmp[k++]=nums[j++];
        //还原数组
        // k=left;
        // for(i=left;i<=right;i++)
        // {
        //     nums[k++]=tmp[i];
        // }
       // memcpy(&nums[left], &tmp[0], (right-left + 1) * sizeof(int));
       
        for (i = 0; i<k; i++)
		    nums[left + i] = tmp[i];
        return ans;    
    }   
};