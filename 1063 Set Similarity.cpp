/*
 * set
1 99 101 87
2    101 87 5 87
3 99 101 18 5 135 18 99
1+2: 2(101 87) / 4(99 101 87 5)
1+3: 2(99 101) / 6(99 101 87 18 5 135)
 */

#include<cstdio>
#include <set>
using namespace std;

const int maxn=55;
set<int> sets[maxn];

double query(int a, int b){
    int nc =0, nt=0;
    auto ita=sets[a].begin();
    auto itb=sets[b].begin();
    while (ita!=sets[a].end()&&itb!=sets[b].end()) {
        if (*ita == *itb) {
            nc++;
            nt++;
            ita++;itb++;
        }
        else if (*ita > *itb) {
            nt++;
            itb++;
        }
        else {
            nt++;
            ita++;
        }
    }
    if (ita==sets[a].end()) {
        for (;itb!=sets[b].end();itb++) {
            nt++;
        }
    }
    else {
        for (;ita!=sets[a].end();ita++) {
            nt++;
        }
    }
    return (double)nc/nt*100;
}

int main() {
    // freopen("1.txt","r",stdin);
    int n,m,a,k,b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&m);
        for (int j=0;j<m;j++) {
            scanf("%d",&a);
            sets[i].insert(a);
        }
    }
    scanf("%d",&k);
    for (int i=0;i<k;i++) {
        scanf("%d %d",&a,&b);

        printf("%.1f%\n", query(a,b));
    }
}


