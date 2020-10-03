/*
 * 图的Dijkstra，包含第二标尺（点权）
 *  */

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;
int n;
int rescue[maxn];   //number of rescue teams in the i-th city
int g[maxn][maxn];  //值为两点间距离
int d[maxn];
int totResc[maxn];
int paths[maxn];    //从起点到点i的最短路径有几种走法
bool vis[maxn];

void Dij(int start) {
    fill(d, d+maxn, INF);
    fill(vis, vis+maxn, false);
    //***重要***需要初始化
    d[start] = 0;
    paths[start] = 1;
    totResc[start] = rescue[start];

    for (int i=0; i<n; i++) {
        int near = -1, minD = INF;
        //找到距离最近的、没访问过的点
        for (int j=0; j<n; j++) {
            if (!vis[j] && d[j]<minD) {
                minD = d[j];
                near = j;
            }
        }
        // 找不到，说明能访问的都已经访问完了，剩下的点和起点不连通
        if (near==-1) return;
        // 访问该点
        vis[near] = true;
        for (int j=0; j<n; j++) {
            if (!vis[j] && g[near][j] > 0 ) {
                if (d[j] > g[near][j]+d[near]) {
                    d[j] = g[near][j]+d[near];
                    // 用最短路径的数据覆盖旧的
                    totResc[j] = totResc[near]+rescue[j];
                    paths[j] = paths[near];
                }
                else if (d[j] == g[near][j]+d[near]) {
                    // 寻找、记录rescue数最多的个数
                    if (totResc[j] < totResc[near]+rescue[j]) {
                        totResc[j] = totResc[near]+rescue[j];
                    }
                    // 该距离的走法数+1
                    paths[j] += paths[near];
                }
            }
        }
    }
}

int main() {
    freopen("1.txt","r",stdin);
    int m, c1, c2, a, b, l;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for (int i=0; i<n; i++) {
        scanf("%d", &rescue[i]);
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &a, &b, &l);
        g[a][b] = g[b][a] = l;
    }

    Dij(c1);
    printf("%d %d", paths[c2], totResc[c2]);

    return 0;
}