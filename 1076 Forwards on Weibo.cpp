/*
 * 图的BFS
 *  */

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

// struct User {
//     vector<int> fan;
// };

const int maxn = 1010;
vector<int> fan[maxn];

int search(int root, int l) {
    int res = 0;
    queue<int> q;
    q.push(root);
    bool visited[maxn];
    fill(visited, visited+maxn, false); // ***重要***因为每次search后visited都会变化，要给它一个初始值全为false
    visited[root] = true;
    while (!q.empty() && l>0) {
        int count = q.size();
        while (count!=0) {
            int u = q.front(); q.pop();
            for (int i=0; i<fan[u].size(); i++) {
                int afan = fan[u].at(i);
                if (visited[afan]) continue;
                visited[afan] = true;
                q.push(afan);
                printf("afan-%d ",afan);
                res++;
            }
            count--;
        }
        l--;
    }
    // printf("\n");
    return res;
}

int main() {
    freopen("1.txt","r",stdin);
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i=1; i<=n; i++) {
        int m;
        scanf("%d",&m);
        for (int j=0; j<m; j++) {
            int tmp;
            scanf("%d",&tmp);
            fan[tmp].push_back(i);
            // printf("%d-%d\n",i,tmp);
        }
    }

    int k;
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        int query;
        scanf("%d",&query);
        printf("%d\n",search(query, l));
    }

    return 0;
}