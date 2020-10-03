#include<cstdio>
#include<vector>

const int maxn=10010;
int g[maxn][maxn];

int main() {
    freopen("1.txt","r",stdin);
    int n,m,a,b,k,nv;
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        g[a][b]=g[b][a]=1;
    }
    scanf("%d",&k);
    for (int i=0;i<m;i++){
        int query[maxn];
        int gg[maxn][maxn];
        memcpy(g,gg,sizeof(gg));
        scanf("%d",&nv);
        for (int j=0;j<nv;j++){
            scanf("%d",&query[j]);
        }
        for (int j=0;j<nv;j++){

        }


    }
}