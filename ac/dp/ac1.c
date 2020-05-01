#include<iostream>
using namespace std;

int n,m;//物品数量  背包体积
int v[10001],w[10001];//体积  价值
int f[10001];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=v[i];j--)
        {

            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[m];
    return 0;
}