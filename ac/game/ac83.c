class Solution {
public:
//所有余数都将在0到k之间。而k-i和i这两个数的个数，决定了这一对是否能k整除。两者相等则配对求和不会有剩下的。 最后mod[0]则是所有为k的整数倍的数个数，如果他们不为偶数，则同样意味着配对时候，有一个会被剩下来，与其他0到k-1的数据配对，这样是不满足题目的。 
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k);//存余数，最大为k-1
        for(auto e:arr)
        {
            mp[(e%k+k)%k]++;
        }
        for(int i=1;i<k;i++)   //除了余数为0的情况，需要进行配对判断
        {
            if(mp[i]!=mp[k-i])
                return false;
        }
        return mp[0]%2==0;//最后在对余数为0的个数判断
    }
};