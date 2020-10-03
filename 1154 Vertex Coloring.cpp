#include<cstdio>
#include<set>
using namespace std;

const int maxn = 10010;

int main() {
    freopen("1.txt","r",stdin);
    int n,m,k;
    scanf("%d %d",&n,&m);
    int g[maxn][2];
    for (int i=0; i<m; i++) {
        scanf("%d %d", &g[i][0],&g[i][1]);
    }
    scanf("%d",&k);
    for (int i=0; i<k; i++) {
        set<int> s;
        int color[maxn];
        for (int j=0; j<n; j++) {
            scanf("%d",&color[j]);
            s.insert(color[j]);
        }
        bool flag = true;
        for (int j=0; j<m; j++) {
            if (color[g[j][0]] == color[g[j][1]]) {
                printf("No\n"); //****No的o是小写啊啊啊啊啊啊****
                flag = false;
                break;
            }
        }
        if(flag) printf("%d-coloring\n",s.size());
    }
}