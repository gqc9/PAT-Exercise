/*
 * 图的Dijkstra，包含第二标尺（点权）
 *  */

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;
int n,s;
int g[maxn][maxn];      //值为两点间距离
int cost[maxn][maxn];   //值为两点间的cost
int dist[maxn];
vector<int> paths[maxn];


// 找到所有距离最短的路径
void Dij(int s) {
    bool vis[maxn];
    fill(vis, vis+maxn, false);
    fill(dist, dist+maxn, INF);
    dist[s] = 0;
    paths[s].push_back(s);
    for (int i=0; i<n; i++) {
        int mid = -1, minD = INF;
        for (int j=0; j<n; j++) {
            if (!vis[j] && dist[j]<minD) {
                mid = j;
                minD = dist[j];
            }
        }
        if (mid == -1) return;
        vis[mid] = true;
        for (int j=0; j<n; j++) {
            if (!vis[j] && g[mid][j] > 0) {
                if (dist[j] > g[mid][j] + dist[mid]) {
                    dist[j] = g[mid][j] + dist[mid];
                    paths[j].clear();
                    paths[j].push_back(mid);
                }
                else if (dist[j] == g[mid][j] + dist[mid]) {
                    paths[j].push_back(mid);
                }
            }
        }
    }
}

vector<int> curpath;
vector<int> bestpath;
int mincost = INF;

// 从所有距离最短的路径中找到cost最低的
void DFS(int idx, int c) {
    if (paths[idx][0] == idx) {  // 到达起点
    // if (idx==s) {
        if (c < mincost) {
            mincost = c;
            curpath.push_back(idx);
            bestpath = curpath;
            curpath.pop_back();
        }
        return;
    }
    curpath.push_back(idx);
    for (int i=0; i<paths[idx].size(); i++) {
        DFS(paths[idx][i], c+cost[idx][paths[idx][i]]);
    }
    curpath.pop_back();
}

int main() {
    freopen("1.txt","r",stdin);
    int m, d, a, b, l, c;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d %d", &a, &b, &l, &c);
        g[a][b] = g[b][a] = l;
        cost[a][b] = cost[b][a] = c;
    }

    Dij(s);
    DFS(d, 0);

    for (int i=bestpath.size()-1; i>=0; i--) {
        printf("%d ", bestpath[i]);
    }
    printf("%d %d", dist[d], mincost);

    return 0;
}