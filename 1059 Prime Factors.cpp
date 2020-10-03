/*
 * 素数：做素数表
 * 注意：最后一个判例是一个小于4的数，不做计算直接输出
 *  */

#include <cstdio>
#include <math.h>

const int maxn = 100000;
int n;
int prime[maxn];
bool mark[maxn];
int priNum = 0;

void findPrime(int n) {
    int sqr = (int) sqrt(1.0 * n);
    for (int i=2; i<sqr; i++) {
        if (!mark[i]) {  // 这个数是素数的话
            prime[priNum++] = i;
            // printf("add%d ", prime[priNum-1]);
            for (int j=i*2; j<sqr; j+=i) {
                mark[j] = true;
            }
        }
    }
}

bool hasPrinted = false;
void print(int p, int k) {
    if (hasPrinted) printf("*");
    if (k==1) {
        printf("%d", p);
    }
    else {
        printf("%d^%d", p, k);
    }
    hasPrinted = true;
}


int main() {
    freopen("1.txt","r",stdin);
    scanf("%d", &n);

    printf("%d=",n);
    if (n<4) {
        printf("%d",n);
        return 0;
    }

    findPrime(n);
    int sqr = (int) sqrt(1.0 * n);
    int cur = 0;
    bool over = false; // 跳出二重循环的标记
    while(n>1) {
        // 找到可以被n整除的素数
        // printf("cur=%d",prime[cur]);
        while (n % prime[cur] != 0) {
            if (prime[cur] > sqr || cur++>=priNum) {
                over = true;
                break;
            }
        }

        if (over) break;

        int k=0;
        while (n % prime[cur] == 0) {
            n /= prime[cur];
            k++;
        }
        print(prime[cur], k);
    }

    if (!hasPrinted) {
        printf("%d",n);
    }

    return 0;
}