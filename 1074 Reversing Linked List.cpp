/*
 * 3/6 分数19/25
 *  */

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const int maxaddr = 100010;
int next[maxaddr];
int data[maxaddr];
int bianli[maxaddr];

int main() {
    freopen("1.txt", "r", stdin);
    int root, n, k, addr, d, next1;
    scanf("%d %d %d", &root, &n, &k);
    for (int i = 0; i<n; i++) {
        scanf("%d %d %d", &addr, &d, &next1);
        data[addr] = d;
        next[addr] = next1;
    }
    int r = root, cur = 1;
    while (r != -1) {
        bianli[cur++] = r;
        r = next[r];
    }
    int ki = k;
    while (ki <= n) {
        for (int i = ki; i>ki-k; i--) {
            if (i==n) {
                printf("%05d %d -1\n", bianli[i], data[bianli[i]]);
                return 0;
            }
            int pre = (i-1!=ki-k) ? i-1 :
                                        (ki+k<=n) ? (ki+k) : ki+1;
            printf("%05d %d %05d\n", bianli[i], data[bianli[i]], bianli[pre]);
        }
        ki += k;
    }
    if (ki!=n) {
        ki -= k;
        for (int i = ki+1; i<=n; i++) {
            if (i!=n) {
                printf("%05d %d %05d\n", bianli[i], data[bianli[i]], bianli[i+1]);
            }
            else {
                printf("%05d %d -1\n", bianli[i], data[bianli[i]]);
            }
        }
    }
}