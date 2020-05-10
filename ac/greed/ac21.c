class Solution {
public:
    static bool compare(const vector<int> a,const vector<int> b)
    {
        return a[0]-a[1]<b[0]-b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),compare);
        int ans=0;
        int n=costs.size()/2;
        for(int i=0;i<n;i++)
        {
            ans+=costs[i][0]+costs[i+n][1];
        }
        return ans;

    }
    
};