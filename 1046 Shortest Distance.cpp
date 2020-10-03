/*
 * 暴力相加，最后一组会超时
 * 改为保存从头到该店的距离和（前缀和），减少相加次数
 *  */

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100;
int dist[maxn];
int n; // 有几个点

/*
// 从左向右，并且l<r
int leftSearch(int l, int r) {
    int res = 0;
    for (int i=l; i<r; i++) {
        res += dist[i-1];
    }
    return res;
}

// 从右向左，并且l<r
int rightSearch(int l, int r) {
    int res = 0;
    for (int i=l; i>1; i--) {
        res += dist[i-2];
    }
    for (int i=r; i<=n; i++) {
        res += dist[i-1];
    }
    return res;
}
*/

int main() {
    freopen("1.txt","r",stdin);
    int m;  // 有几组数据
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &dist[i]);
        if (i>0) dist[i] += dist[i-1];
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a>b) {
            int tmp = b;
            b = a;
            a = tmp;
        }
        // int left = leftSearch(a,b);
        // int right = rightSearch(a,b);
        a--;b--;
        int left,right;
        if (a>=1) {
            left = dist[b-1]-dist[a-1];
            right = dist[n-1] - dist[b-1] + dist[a-1];
        }
        else {
            left = dist[b-1];
            right = dist[n-1] - dist[b-1];
        }
        // printf("%d, %d\n", left,right);
        printf("%d\n", min(left,right));
    }

    return 0;
}