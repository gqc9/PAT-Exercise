/*
 * 层序遍历，找出节点数最多的那一层
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main() {
    freopen("F:/bupt/PAT/1.txt","r",stdin);
    const int maxn = 110;
    vector<int> tree[maxn];
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        int id, k;
        scanf("%d %d", &id, &k);
        for (int j=0; j<k; j++) {
            int child;
            scanf("%d",&child);
            tree[id].push_back(child);
        }
    }

    queue<int> q;
    q.push(1);
    int level = 1, maxPopulation = 0, maxLevel = 1;
    while(!q.empty()) {
        int count = q.size(), population = 0;
        while(count!=0) {
            int idx = q.front();
            q.pop();
            population++;
            for (int i=0; i<tree[idx].size(); i++) {
                q.push(tree[idx].at(i));
            }
            if (maxPopulation < population) {
                maxPopulation = population;
                maxLevel = level;
            }
            count--;
        }
        level++;
    }

    printf("%d %d", maxPopulation, maxLevel);

    return 0;
}