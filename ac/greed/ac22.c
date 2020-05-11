class Solution {
public:
    static bool compare(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),compare);
        int end=intervals[0][1];
        int count=0;//相交的区间数
        for(int i=1;i<intervals.size();i++)
        {
            if(end>intervals[i][0])//是相交区间，是要删除的
            {
                ++count;
            }
            else
            {
                end=intervals[i][1];//不相交，更新
            }
        }
        return count;
    }
};