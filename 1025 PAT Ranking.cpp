#include <cstdio>
#include <cstring>
#include <algorithm> //sort()
using namespace std;

struct Testee {
    char id[15];
    int score;
    int location_num;
    int location_rank;
} t[30010];

bool cmp (Testee a, Testee b) {
    if (a.score!=b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}

int main() {
    FILE* fp = fopen("input.txt", "r");
    int n, k, totalNum=0;
    fscanf(fp, "%d", &n);
    for (int i=0; i<n; i++) {
        int start=totalNum;
        fscanf(fp, "%d", &k);
        for (int j=0; j<k; j++) {
            t[totalNum].location_num = i+1;
            fscanf(fp, "%s %d", t[totalNum].id, &t[totalNum].score);
            totalNum++;
        }
        sort(t+start, t+totalNum, cmp);
        //分配区域排名
        int localR=1;
        for (int j=start; j<totalNum; j++) {
            if (j!=start && t[j].score!=t[j-1].score) {
                localR=j-start+1;
            }
            t[j].location_rank = localR;
        }
    }
    printf("%d\n", totalNum);
    sort(t, t+totalNum, cmp);
    int rankByK[301];
    int r=1;
    for (int i=0; i<totalNum; i++) {
        if (i!=0 && t[i].score!=t[i-1].score) {
            r = i+1;
        }
        printf("%s %d %d %d\n", t[i].id, r, t[i].location_num, t[i].location_rank);
    }
    return 0;
}