/*
 * 找出层数最低（最靠近根节点）的叶子节点的层数，及那一层的叶子结点个数
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
    const int maxn = 1010;
    vector<int> tree[maxn];
    int n; double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i=0; i<n; i++) {
        int ki;
        scanf("%d", &ki);
        for (int j=0; j<ki; j++) {
            int child;
            scanf("%d", &child);
            tree[i].push_back(child);
        }
    }

    queue<int> q;
    q.push(0);
    int level = 0;
    int count, c, num=0;
    double lowest = 0.0;
    bool found = false;
    while(!q.empty() && !found) {
        count = q.size();
        c = count;
        while(c!=0) {
            int idx = q.front();
            q.pop();
            if (tree[idx].size() == 0 && !found) {
                lowest = p * pow(1+r/100, level);
                found = true;
            }
            if (tree[idx].size() == 0 && found) {
                num++;
            }
            for (int i=0; i<tree[idx].size(); i++) {
                q.push(tree[idx].at(i));
            }
            c--;
        }
        level++;
    }

    printf("%.4f %d", lowest, num);

    return 0;
}