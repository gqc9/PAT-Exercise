/*
 * 9.6 并查集例题 好朋友
 */

#include <cstdio>

const int maxn = 110;
int friends[maxn];
bool isRoot[maxn];

int findRoot(int idx) {
    while (friends[idx] != idx) {
        idx = friends[idx];
    }
    return idx;
}

void Union(int a, int b) {
    int aRoot = findRoot(a);
    int bRoot = findRoot(b);
    friends[aRoot] = bRoot;
}

void init(int n) {
    for (int i=0; i<n; i++) {
        friends[i] = i;
    }
}

int main(){
    freopen("96.txt","r",stdin);
    int n, m;
    int a, b;
    scanf("%d %d",&n, &m);
    init(n);
    for (int i=0; i<m; i++) {
        scanf("%d %d",&a,&b);
        Union(a,b);
    }

    int res = 0;
    for (int i=0; i<n; i++) {
        int iRoot = findRoot(i);
        if (!isRoot[iRoot]) res++;
        isRoot[iRoot] = true;
    }

    printf("%d",res);
}