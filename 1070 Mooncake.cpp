#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
struct mooncake {
    double amount;
    double totpri;
    double onepri;
} mc[maxn];

bool cmp(mooncake a, mooncake b) {
    return a.onepri>b.onepri;
}

int main() {
    // freopen("1.txt","r",stdin);
    int n;
    double d;
    scanf("%d %lf", &n, &d);
    for (int i = 0; i<n; i++) {
        scanf("%lf", &mc[i].amount);
    }
    for (int i = 0; i<n; i++) {
        scanf("%lf", &mc[i].totpri);
        mc[i].onepri = mc[i].totpri / mc[i].amount;
    }

    sort(mc, mc+n, cmp);
    double profit = 0.0;
    double totamt = 0.0;
    for (int i = 0; i<n; i++) {
        if (mc[i].amount + totamt <= d) {   //能全放下
            profit += mc[i].totpri;
            totamt += mc[i].amount;
        }
        else {
            double diff = d - totamt;
            profit += diff * mc[i].onepri;
            break;
        }
    }

    printf("%.2f\n", profit);
}