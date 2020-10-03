#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int gcd(int a, int b) {
    return (b==0) ? a : gcd(b, a%b);
}

int main() {
    const int maxn = 200010;
    int n;
    scanf("%d", &n);
    long double d;
    int a[maxn];
    int b[maxn];
    map<long double, int> m;
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &b[i]);
    }

    int maxZero = 0;
    int extra = 0;
    for (int i=0; i<n; i++) {
        if (a[i]==0 ) {
            if (b[i]==0) extra++;
            continue;
        }
        int gcd1 = gcd(a[i], b[i]);
        a[i] /= gcd1;
        b[i] /= gcd1;
        d = (long double)a[i] / b[i];
        // if (m.find(d) == m.end()) {
        //     m[d] = 1;
        // }
        // else {
            m[d]++;
        // }
    }
    for (auto it = m.begin(); it!= m.end(); it++) {
        if (it->second > maxZero) maxZero = it->second;
    }

    printf("%d", maxZero + extra);
    return 0;
}