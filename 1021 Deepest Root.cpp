/*
 * 图的DFS
 * res用vector保存会答案错误，用set就AC。
 * 原因：会保存重复元素。
 * 或者用vector，但是打印前检查重复。
 *  */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int maxn = 10010;
vector<int> g[maxn];
bool vis[maxn];
int maxHeight = 0;
vector<int> roots;

void dfs(int idx, int height) {
    if (height > maxHeight) {
        maxHeight = height;
        roots.clear();
        roots.push_back(idx);
        // printf("new push %d\n",idx);
    }
    else if (height == maxHeight) {
        roots.push_back(idx);
        // printf("push %d\n",idx);
    }
    vis[idx] = true;
    for (int i=0; i<g[idx].size(); i++) {
        if (!vis[g[idx][i]]) {
            dfs(g[idx][i], height+1);
        }
    }
}

int main() {
    freopen("1.txt","r",stdin);
    int n;  // 节点数
    int a, b;
    scanf("%d", &n);
    // g.resize(n+1);
    for (int i=0; i<n-1; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int errCnt = 0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            errCnt++;
            dfs(i,0);
        }
    }
    if (errCnt>1) {
        printf("Error: %d components", errCnt);
        return 0;
    }

    set<int> res;
    for (int i=0; i<roots.size(); i++) {
        res.insert(roots[i]);
    }
    roots.clear();

    fill(vis, vis+maxn, false);
    dfs(roots[0], 0);

    for (int i=0; i<roots.size(); i++) {
        res.insert(roots[i]);
    }

    // set已经由小到大排序过
    // sort(res.begin(), res.end());

    for (auto it=res.begin(); it!=res.end(); it++) {
        printf("%d\n",*it);
    }

    return 0;
}