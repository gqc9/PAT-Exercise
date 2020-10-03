/*
 * 找出层数最高（离根节点最远）的叶子节点的层数，及那一层的叶子结点个数
 * 层序遍历
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main() {
    freopen("F:/bupt/PAT/1.txt","r",stdin);
    // vscode里maxn太大了，会溢出，pta里不会
    const int maxn = 100010;
    vector<int> tree[maxn];
    int n; double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i=0; i<n; i++) {
        int par;
        scanf("%d", &par);
        if (par==-1) {
            tree[maxn-1].push_back(i);
        }
        else {
            tree[par].push_back(i);
        }
    }

    queue<int> q;
    q.push(maxn-1);
    int level = 0;
    int count, c;
    while(!q.empty()) {
        count = q.size();
        c = count;
        while(c!=0) {
            int idx = q.front();
            q.pop();
            for (int i=0; i<tree[idx].size(); i++) {
                q.push(tree[idx].at(i));
            }

            c--;
        }
        level++;
    }
    double highest = p * pow(1+r/100, level-2);
    printf("%.2f %d", highest, count);

    return 0;
}