#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 105;
int g[N][N];                                      //存地图
int d[N][N];                                      //存每个点到起点的距离
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //定义偏移量
PII pre[N][N];                                    //记录路径 记录当前的点从哪个点走过来
int n, m;

int bfs()
{
    queue<PII> q;

    //将所有的距离初始化成-1
    memset(d, -1, sizeof(d));
    d[0][0] = 0; //起点距离初始化成0

    //初始状态放入队列
    q.push({0, 0});

    while (!q.empty())
    {
        //取出队头
        PII p = q.front();
        q.pop();

        //往四个方向扩展队头
        for (int i = 0; i < 4; i++)
        {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) //d[x][y] == -1表示这个点是第一次搜到
            {
                d[x][y] = d[p.first][p.second] + 1; //距离加一
                pre[x][y] = p;
                q.push({x, y}); //把当前的点加入队列
            }
        }
    }
    return d[n - 1][m - 1];
     
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &g[i][j]);
    }

    printf("%d\n", bfs());
    
    //输出最短路径 倒着输出
    int x = n - 1, y = m - 1;
    while (x || y)
    {
        cout << x << " " << y << endl;
        PII t = pre[x][y];
        x = t.first;
        y = t.second;
    }

    return 0;
}
