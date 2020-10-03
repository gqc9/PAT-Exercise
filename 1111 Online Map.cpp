/*
 * Dijkstra+DFS
 *  */

#include <cstdio>
#include <vector>
using namespace std;

const int INF = 1000000000;
const int maxn = 550;
int n;
int l[maxn][maxn];  //l[v1][v2]是v1->v2的length
int t[maxn][maxn];
int ld[maxn];
vector<int> lpaths[maxn];
vector<int> lbestpath;
vector<int> lcurpath;
int minT = INF;
int td[maxn];
vector<int> tpaths[maxn];
vector<int> tbestpath;
vector<int> tcurpath;
int minL = INF;

void DijL(int s) {
    bool vis[maxn];
    fill(vis, vis+n, false);
    fill(ld, ld+maxn, INF);
    ld[s] = 0;
    lpaths[s].push_back(s);
    for (int i=0; i<n; i++) {
        int mid=-1, minD=INF;
        for (int j=0; j<n; j++) {
            if (!vis[j] && ld[j] < minD) {
                mid = j;
                minD = ld[j];
            }
        }
        if (mid == -1) return;
        vis[mid] = true;
        for (int j=0; j<n; j++) {
            if (!vis[j] && l[mid][j] > 0) {
                if (ld[j] > ld[mid] + l[mid][j]) {
                    ld[j] = ld[mid] + l[mid][j];
                    lpaths[j].clear();
                    lpaths[j].push_back(mid);
                }
                else if (ld[j] == ld[mid] + l[mid][j]) {
                    lpaths[j].push_back(mid);
                }
            }
        }
    }
}

void DFSL(int idx, int c) {
    if (lpaths[idx][0] == idx) {
        if (c < minT) {
            minT = c;
            lcurpath.push_back(idx);
            lbestpath = lcurpath;
            lcurpath.pop_back();
        }
        return ;
    }
    lcurpath.push_back(idx);
    for (int i=0; i<lpaths[idx].size(); i++) {
        DFSL(lpaths[idx][i], c + t[lpaths[idx][i]][idx]);
    }
    lcurpath.pop_back();
}


void DijT(int s) {
    bool vis[maxn];
    fill(vis, vis+n, false);
    fill(td, td+maxn, INF);
    td[s] = 0;
    tpaths[s].push_back(s);
    for (int i=0; i<n; i++) {
        int mid=-1, minD=INF;
        for (int j=0; j<n; j++) {
            if (!vis[j] && td[j] < minD) {
                mid = j;
                minD = td[j];
            }
        }
        if (mid == -1) return;
        vis[mid] = true;
        for (int j=0; j<n; j++) {
            if (!vis[j] && t[mid][j] > 0) {
                if (td[j] > td[mid] + t[mid][j]) {
                    td[j] = td[mid] + t[mid][j];
                    tpaths[j].clear();
                    tpaths[j].push_back(mid);
                }
                else if (td[j] == td[mid] + t[mid][j]) {
                    tpaths[j].push_back(mid);
                }
            }
        }
    }
}

void DFST(int idx, int c) {
    if (tpaths[idx][0] == idx) {
        if (c < minL) {
            minL = c;
            tcurpath.push_back(idx);
            tbestpath = tcurpath;
            tcurpath.pop_back();
        }
        return ;
    }
    tcurpath.push_back(idx);
    for (int i=0; i<tpaths[idx].size(); i++) {
        DFST(tpaths[idx][i], c + 1);
    }
    tcurpath.pop_back();
}


int main() {
    freopen("1.txt","r",stdin);
    int m, v1,v2, oneway, len, time;
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++) {
        scanf("%d %d %d %d %d",&v1,&v2, &oneway, &len, &time);
        l[v1][v2] = len;
        t[v1][v2] = time;
        if (!oneway) {
            l[v2][v1] = len;
            t[v2][v1] = time;
        }
    }
    int start, end;
    scanf("%d %d",&start,&end);
    DijL(start);
    DFSL(end, 0);
    DijT(start);
    DFST(end, 0);

    if (lbestpath == tbestpath) {
        printf("Distance = %d; Time = %d: ", ld[end], td[end]);
        for (int i=lbestpath.size()-1; i>=0; i--) {
            printf("%d",lbestpath[i]);
            if (i!=0) printf(" -> ");
        }
        return 0;
    }

    printf("Distance = %d: ", ld[end]);
    for (int i=lbestpath.size()-1; i>=0; i--) {
        printf("%d",lbestpath[i]);
        if (i!=0) printf(" -> ");
    }
    printf("\n");
    printf("Time = %d: ", td[end]);
    for (int i=tbestpath.size()-1; i>=0; i--) {
        printf("%d",tbestpath[i]);
        if (i!=0) printf(" -> ");
    }


}