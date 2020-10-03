/*
 *
 *  */

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int hobby[maxn];
int people[maxn];

void init(int n) {
    for (int i = 1; i<=n; i++) {
        people[i] = i;
    }
}

int findFather(int idx) {
    while (people[idx] != idx) {
        idx = people[idx];
    }
    return idx;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa!=fb) {
        people[fa] = fb;
    }
}

bool cmp(int a, int b) {
    return a>b;
}

int main() {
    freopen("1.txt", "r", stdin);
    int n, k, h;
    fill(hobby, hobby+maxn, 0);
    scanf("%d", &n);
    init(n);
    for (int i = 1; i<=n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j<k; j++) {
            scanf("%d", &h);
            if (hobby[h]==0) hobby[h] = i;
            else {
                Union(i, hobby[h]);
            }

        }
    }

    int isRoot[maxn];
    fill(isRoot, isRoot+maxn, 0);
    int cnt = 0;
    for (int i = 1; i<=n; i++) {
        int f = findFather(i);
        if (isRoot[f] == 0) {
            cnt++;
        }
        isRoot[f] ++;
    }

    sort(isRoot, isRoot+n, cmp);

    printf("%d\n", cnt);
    for (int i = 0; i<cnt; i++) {
        printf("%d", isRoot[i]);
        if (i!=cnt) printf(" ");
    }

    return 0;
}