/*
 * 6/10 分数23/30
 * Dijkstra+DFS，有三个标尺
 *  */

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1000000000;
const int maxn = 510;
const int half = 5;
int n;
int bike[maxn];
int time[maxn][maxn];
int d[maxn]; //从起点到i的距离
vector<int> paths[maxn];

void Dij(int start) {
    bool vis[maxn];
    fill(vis, vis+maxn, false);
    fill(d, d+maxn, INF);
    d[start] = 0;
    paths[start].push_back(start);
    for (int i = 0; i<n; i++) {
        int mid = -1, minD = INF;
        for (int j = 0; j<=n; j++) {    //******里面的顶点是从0开始，0代表起点，到n结束，包含n
            if (!vis[j] && d[j]<minD) {
                minD = d[j];
                mid = j;
            }
        }
        if (mid==-1) return;
        vis[mid] = true;
        for (int j = 0; j<=n; j++) {
            if (!vis[j] && time[mid][j]>0) {
                if (time[mid][j] + d[mid] < d[j]) {
                    d[j] = time[mid][j] + d[mid];
                    paths[j].clear();
                    paths[j].push_back(mid);
                }
                else if (time[mid][j] + d[mid] == d[j]) {
                    paths[j].push_back(mid);
                }
            }
        }
    }
}

int minNum = -INF;  //need是负数，负的表示需要额外的数量，正的表示多出来的数量
int minDuo = INF;   //多出来的要从终点拿回来
vector<int> bestpath;
vector<int> curpath;

void DFS(int idx, int need, int duo) {
    if (paths[idx][0]==idx) {   //遍历到终点了
        if (need > minNum) {
            minNum = need;
            minDuo = duo;
            curpath.push_back(idx);
            bestpath = curpath;
            curpath.pop_back();
        }
        else if (need==minNum) {
            if (duo<minDuo) {
                minDuo = duo;
                curpath.push_back(idx);
                bestpath = curpath;
                curpath.pop_back();
            }
        }
    }
    else {
        curpath.push_back(idx);
        for (int i = 0; i<paths[idx].size(); i++) {
            int newNeed = need + (bike[paths[idx][i]] - half);
            int newDuo = duo;
            if (newNeed>0) {
                newDuo += newNeed;
                newNeed = 0;
            }
            DFS(paths[idx][i], newNeed, newDuo);
        }
        curpath.pop_back();
    }
}

int main() {
    freopen("1.txt", "r", stdin);
    int cmax, sp, m, a, b, t;
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    bike[0] = 5;
    for (int i = 1; i<=n; i++) {
        scanf("%d", &bike[i]);
    }
    for (int i = 0; i<m; i++) {
        scanf("%d%d%d", &a, &b, &t);
        time[a][b] = time[b][a] = t;
    }
    Dij(0);
    DFS(sp, -5, 0);
    minNum = -minNum;
    bike[0] = minNum;

    printf("%d ", minNum);
    for (int i = bestpath.size()-1; i>=0; i--) {
        printf("%d", bestpath[i]);
        if (i!=0) printf("->");
    }
    printf(" %d",minDuo);

    return 0;
}