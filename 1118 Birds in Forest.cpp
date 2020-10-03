/*
 * 并查集
 * 如果findFather没有压缩路径，有一判例会超时
 *  */

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10010;
int tree[maxn];

void init() {
    for (int i=1; i<=maxn; i++) {
        tree[i] = i;
    }
}

int findFather(int idx) {
    // while (idx != tree[idx]) {
    //     idx = tree[idx];
    // }
    // return idx;
    // 压缩路径
    return (idx == tree[idx]) ? idx : tree[idx] = findFather(tree[idx]);
}

void update(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    tree[fb] = fa;
}

int main() {
    freopen("1.txt","r",stdin);
    int n,k,b1,bi,q,i1,i2,f1,f2;
    int bn = 0; //最大的idx
    init();
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&k,&b1);
        if (b1 > bn) bn = b1;
        for (int j=1; j<k; j++) {
            scanf("%d",&bi);
            if (bi > bn) bn = bi;
            update(b1,bi);
        }
    }

    int treecnt = 0;
    bool isFather[maxn];
    fill(isFather, isFather+maxn-1, false);
    for (int i=1; i<=bn; i++) {
        int fi = findFather(i);
        if (!isFather[fi]) {
            treecnt++;
            isFather[fi] = true;
        }
    }
    printf("%d %d\n", treecnt, bn);
    scanf("%d",&q);
    for (int i=0; i<q; i++) {
        scanf("%d %d",&i1,&i2);
        f1 = findFather(i1);
        f2 = findFather(i2);
        if (f1==f2) {
            printf("Yes\n");
        }
        else printf("No\n");
    }
}