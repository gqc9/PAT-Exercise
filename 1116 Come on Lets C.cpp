/*
 * 检查素数
 *  */
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<math.h>

const int maxn = 10010;
const int maxid = 10010;
int rank[maxid]; //i是id，rank[id]是该id的排名
bool pri[maxn];  //false是素数、true不是
bool check[maxn];

void PrimeList(int n) {
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i<=sqr; i++) {
        if (pri[i]) continue;
        for (int j = 2*i; j<=n; j += i) {
            pri[j] = true;
        }
    }
    return;
}

int main() {
    freopen("1.txt", "r", stdin);
    int n, id, k;
    bool res;
    scanf("%d", &n);
    for (int i = 1; i<=n; i++) {
        scanf("%d", &id);
        rank[id] = i;
    }
    PrimeList(n);
    scanf("%d", &k);
    for (int i = 0; i<k; i++) {
        scanf("%d", &id);
        printf("%04d: ", id);
        if (rank[id] == 0) {
            printf("Are you kidding?\n");
        }
        else if (check[id]) {
            printf("Checked\n");
        }
        else if (rank[id] == 1) {
            printf("Mystery Award\n");
        }
        else {
            res = pri[rank[id]];
            if (res || rank[id] == 2) {
                printf("Chocolate\n");
            }
            else {
                printf("Minion\n");
            }
        }
        check[id] = true;
    }

    return 0;
}