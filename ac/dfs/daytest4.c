#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long count=0;
int  dfs(vector<int>& v,int index,long long sum,long long chen)
{
    int count=0;
    for(int i=index;i<v.size();i++)
    {
        sum+=v[i];
        chen*=v[i];
        if(sum>chen) count+=1+dfs(v,i+1,sum,chen);
        else if(v[i]==1) count+=dfs(v,i+1,sum,chen);
        else 
            break; //小于且不是1，必然是大于的，且排了序，后面的绝对不满足了，剪枝
        sum-=v[i];
        chen/=v[i];
        while( i<(v.size()-1)&& (v[i]==v[i+1])) ++i;
    }
    return count;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        long long sum=0,chen=1;
        cout<<dfs(v,0,sum,chen)<<endl;
    }
    return 0;
}