/*
 * 特殊判例：sum=0
 *  */

#include <cstdio>
#include <stdlib.h>  //abs()

const int maxn = 7;

int main() {
    freopen("1001.txt","r",stdin);
    int a, b;
    scanf("%d %d", &a, &b);

    int sum = a+b;
    //正负号问题
    bool sign = (sum>0) ? true : false;
    sum = abs(sum);
    if (sum==0) {
        printf("0");
        return 0;
    }

    int len = 0;
    char str[maxn];
    while (sum != 0) {
        int c = sum % 10; // 从个位数开始
        str[len++] = c;
        sum /= 10;
    }

    if (!sign) printf("-"); //负号
    if (len%3 != 0) {
        for (int i=len-1; i>=len-len%3; i--) {
            printf("%d", str[i]);
        }
        if (len>3) printf(",");
    }

    int count = 0;
    for (int i=len-len%3-1; i>=0; i--) {
        printf("%d", str[i]);
        if ((++count == 3) && i!=0) {
            printf(",");
            count = 0;
        }
    }

    return 0;
}