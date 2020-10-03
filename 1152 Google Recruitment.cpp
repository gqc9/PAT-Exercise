/*
 * 素数：判断是否是素数
 * 注意：题目中说明要补零，所以不能输出int，要输出substr
 *  */

#include <cstdio>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num<=1) return false;
    int sqr = (int) sqrt(1.0 * num);
    for (int i=2; i<sqr; i++) {
        if (num % i == 0) return false;
    }
    return true;
}


int main() {
    freopen("1.txt","r",stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    string str;
    cin >> str;

    for (int i=0; i+k<=n; i++) {
        string sub = str.substr(i, k);
        int num = stoi(sub);
        if (isPrime(num)) {
            cout<<sub;  // 这里不能用printf，这种用法不对
            // printf("%s",sub);
            return 0;
        }
    }

    // 如果没找到
    printf("404");

    return 0;
}