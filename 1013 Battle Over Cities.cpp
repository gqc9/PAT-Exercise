/*
 * 图的遍历。计算连通分量个数。
 *  */

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int G[maxn][maxn];
int n;  // 节点个数
bool visited[maxn];

void dfs(int idx) {
    visited[idx] = true;
    for (int i=1; i<=n; i++) {  //***重要***序号是从1~n，注意循环条件
        if (G[idx][i] > 0 && !visited[i]) {
            dfs(i);
        }
    }
}


int main() {
    freopen("1.txt","r",stdin);
    int m, k, a, b, idx;
    scanf("%d %d %d", &n, &m, &k);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    for (int i=0; i<k; i++) {
        scanf("%d", &idx);
        fill(visited, visited+maxn, false);
        visited[idx] = true;
        int count = 0;
        for (int j=1; j<=n; j++) {
            if (visited[j]) continue;
            dfs(j);
            count++;
        }
        printf("%d\n", count-1);
    }

    return 0;
}