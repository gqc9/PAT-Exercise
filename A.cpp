#include <cstdio>

int main() {
    int n, L, v, left, right;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d %d", &L, &v, &left, &right);
        int count = 0;
        count += (left-1) / v;
        right = right - right%v;
        count += (L-right) / v;
        printf("%d\n", count);
    }
    return 0;
}