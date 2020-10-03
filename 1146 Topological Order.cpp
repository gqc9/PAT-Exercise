/*
 * 拓扑序列
 *  */

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include <vector>
#include<set>
using namespace std;

const int maxn = 1010;
vector<int> g[maxn];
int indegree[maxn];
set<int> s[maxn];
vector<int> res;

int main() {
    freopen("1.txt", "r", stdin);
    int n, m, a, b, k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i<m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        indegree[b]++;
    }
    scanf("%d", &k);
    for (int i = 0; i<k; i++) {
        int arr[maxn];
        int query[maxn];
        copy(indegree, indegree+n+1, arr);
        for (int j = 0; j<n; j++) {
            scanf("%d", &query[j]);
            /***为什么不能在循环里直接检查？***
             * 因为这里如果break了的话，scanf的位置就会错了
             */
            //if (arr[query[j]]!=0) {
            //    res.push_back(i);
            //    break;
            //}
            //for (int x = 0; x<g[query[j]].size(); x++) {
            //    arr[g[query[j]][x]]--;
            //}
        }
        for (int j = 0; j < n; j++) {
            if (arr[query[j]] > 0) {
                res.push_back(i);
                break;
            }
            for (int x = 0; x<g[query[j]].size(); x++) {
                arr[g[query[j]][x]]--;
            }
        }
    }
    for (int i = 0; i<res.size(); i++) {
        if (i>0)printf(" ");
        printf("%d", res[i]);
    }
}