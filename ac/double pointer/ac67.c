struct compare//multiset容器的比较器规则 仿函数
{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b)const 
    {
        return (a.second-a.first)<(b.second-b.first);
    }
};
class Solution {   
public:
//滑动窗口，先找出和为target的子数组区间，再根据长度排序，两两比较，不重叠时，便满足题意
    int minSumOfLengths(vector<int>& arr, int target) {
        int minlen=INT_MAX;
        int i=0,j=0;
        int sum=0;
        multiset<pair<int,int>,compare> st;
        while(j<arr.size())
        {
            sum+=arr[j];
            j++;
            if(sum<target) //窗口右移
                continue;
            while(sum>target) //窗口左移
            {
                sum-=arr[i];
                i++;
            }
            if(sum==target)//满足的子数组区间
            {
                st.insert({i,j-1}); //插入时是按自己定义的仿函数，根据长度排序
            }  
        }
        // for(auto e:st)
        // {
        //     cout<<e.first<<":"<<e.second<<endl;
        // }
        //在比较
        for(auto it=st.begin();it!=st.end();it++)
        {
            if(minlen!=INT_MAX)//因为是用长度排了序的，第一次求出来的便是答案了
                break;
            // if(2*(it->second-it->first+1) >= minlen)
            //     break;
            auto it2=it;
            for(auto it2=it;it2!=st.end();it2++)
            {
                if(it2->first>it->second || it2->second<it->first){
                    minlen=min(minlen,it2->second-it2->first + it->second-it->first +2);
                    break;
                }
            }
        }
        return minlen==INT_MAX? -1: minlen;
    }
};