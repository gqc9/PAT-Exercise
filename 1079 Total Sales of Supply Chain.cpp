/*
 * 层序遍历
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main() {
    freopen("F:/bupt/PAT/1.txt","r",stdin);
    const int maxn = 100010;
    vector<int> tree[maxn];
    int amounts[maxn];
    int n; double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i=0; i<n; i++) {
        int ki, child;
        scanf("%d", &ki);
        if (ki>0) {
            vector<int> childs;
            for (int j=0; j<ki; j++) {
                scanf("%d", &child);
                childs.push_back(child);
            }
            tree[i] = childs;
        }
        else {
            scanf("%d",&amounts[i]); //产品数量
        }
    }

    queue<int> q;
    q.push(0);
    int level = 0;
    double totalP = 0.0;
    while(!q.empty()) {
        int count = q.size();
        while(count!=0) {
            // printf("count=%d\n",count);
            int idx = q.front();
            q.pop();
            // printf("idx=%d\n",idx);
            if (tree[idx].size()!=0) {
                for (int i=0; i<tree[idx].size(); i++) {
                    q.push(tree[idx].at(i));
                }
            }
            else { //是leaf
                totalP += amounts[idx] * p * pow(1+r/100, level);
            }
            count--;
        }
        level++;
    }

    printf("%.1f", totalP);

    return 0;
}