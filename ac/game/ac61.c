class Solution {
    static bool compare(pair<int,int>a,pair<int,int>b)
    {
        if(a.second==b.second)
            return a.first>b.first;
        return a.second>b.second;
    }
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<pair<int,int>> p;
        sort(arr.begin(),arr.end());
        int mid=arr[(arr.size()-1)/2];
        for(auto a:arr)
        {
            p.push_back(make_pair(a,abs(a-mid)));
        }
        sort(p.begin(),p.end(),compare);
        vector<int> ret;
        for(int i=0;i<k;i++)
        {
            ret.push_back(p[i].first);
        }
        return ret;
    }
};