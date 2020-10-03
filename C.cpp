#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    const int maxn = 100010;
    int n, m, ai, bi;
    scanf("%d %d", &n, &m);
    int total = 0;
    int totcomp = 0;
    int diff[maxn];
    for (int i=0; i<n; i++) {
        scanf("%d %d", &ai, &bi);
        total += ai;
        totcomp += bi;
        diff[i] = ai - bi;
    }
    if (total <= m) {
        printf("0");
        return 0;
    }
    if (totcomp > m) {
        printf("-1");
        return 0;
    }
    int need = total - m;
    sort(diff, diff+n);
    int totdiff = 0, count = 0;
    for (int i=n-1; i>=0; i--) {
        totdiff += diff[i];
        count++;
        if (totdiff >= need) {
            break;
        }
    }
    printf("%d", count);
    // int arr[maxn][maxn];
    // for (int i=0; i<n; i++) {
    //     for (int j=1; j<=n; j++) {
    //         if (i == 0) {
    //             arr[i][j] = diff[i];
    //         }
    //         else {
    //             int last = arr[i-1][j];
    //             int now = diff[i] + arr[i-1][j-1];
    //             arr[i][j] = max(last, now);
    //         }
    //     }
    // }
    // int count = -1;
    // for (int i=1; i<=n; i++) {
    //     if (arr[n-1][i] >= need) {
    //         count = i;
    //         break;
    //     }
    // }
    // printf("%d", count);
    return 0;
}