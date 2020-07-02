class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size(),col=matrix[0].size();
        int left=matrix[0][0];
        int right=matrix[row-1][col-1];
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(check(matrix,mid,k,row))  //统计比基准值mid小的树的个数，在判断区间，逼近答案
            {
                right=mid;
            }
            else
                left=mid+1;
        }
        return left;
    }
    bool check(vector<vector<int>>& matrix,int mid,int k,int n)
    {
        int i=n-1,j=0;
        int count=0;
        while(i>=0 && j<n)
        {
            if(matrix[i][j] <= mid)
            {
                count+=i+1;//统计小于mid的个数
                j++;
            }
            else
            {
                i--;
            }
        }
        return count>=k; //大于，则要缩小
    }
};