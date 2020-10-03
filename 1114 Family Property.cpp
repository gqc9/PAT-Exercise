#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

struct Family {
    set<int> ids;
    int sets = 0;
    int area = 0;
    double avset;
    double avarea;
    int id;
};

struct Node {
    int set;
    int area;
};

const int maxn = 1010;
const int maxid = 10000;
int n;
int father[maxid];
Family* fams[maxid];
bool isMem[maxid];
Node* nodes[maxid];

void init() {
    for (int i = 0; i<maxid; i++) {
        father[i] = i;
    }
}

int findFather(int idx) {
    while (father[idx] != idx) {
        idx = father[idx];
    }
    return idx;
}

void updateFather(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    father[fa] = fb;
    if (fams[fb] == NULL) {
        fams[fb] = fams[fa];
    }
    else{
        fams[fb]->ids.insert(fa);
        if (fams[fa]->ids.size()!=0) {
            fams[fb]->ids.insert(fams[fa]->ids.begin(), fams[fa]->ids.end());
        }
    }
    fams[fb]->ids.insert(fb);
}

bool cmp(Family* f1, Family* f2) {
    if (f1->avarea != f2->avarea) {
        return f1->avarea > f2->avarea;
    }
    else {
        return f1->id < f2->id;
    }
}

int main() {
    freopen("1.txt", "r", stdin);
    init();
    scanf("%d", &n);
    int id, f1, f2, numson, set1, area1, fid;
    int sons[maxn];
    for (int i = 0; i<n; i++) {
        scanf("%d %d %d", &id, &f1, &f2);
        scanf("%d", &numson);
        for (int j = 0; j<numson; j++) {
            scanf("%d", &sons[j]);
        }
        scanf("%d %d", &set1, &area1);
        fid = findFather(id);
        if (fams[fid] == NULL) {
            fams[fid] = new Family;
        }
        fams[fid]->ids.insert(id);
        nodes[id] = new Node;
        nodes[id]->set = set1;
        nodes[id]->area = area1;
        if (f1!=-1) updateFather(id, f1);
        if (f2!=-1) updateFather(id, f2);
        for (int j = 0; j<numson; j++) {
            updateFather(id, sons[j]);
        }
        isMem[id] = true;
    }

    int famcnt=0;
    bool isFather[maxid];
    vector<Family*> famres;
    fill(isFather, isFather+maxid-1, false);
    for (int i = 0; i<maxid; i++) {
        if (!isMem[i]) continue;
        int fi = findFather(i);
        if (!isFather[fi]) {
            famcnt++;
            isFather[fi] = true;
            famres.push_back(fams[fi]);
        }
    }

    for (int i = 0; i<famcnt; i++) {
        int minID = 10000;
        for (auto j = famres[i]->ids.begin(); j!=famres[i]->ids.end(); j++) {
            if (*j < minID) minID = *j;
            if (nodes[*j] == NULL) continue;
            famres[i]->sets += nodes[*j]->set;
            famres[i]->area += nodes[*j]->area;
        }
        famres[i]->id = minID;
        famres[i]->avset = (double)famres[i]->sets / famres[i]->ids.size();
        famres[i]->avarea = (double)famres[i]->area / famres[i]->ids.size();
    }



    printf("%d\n", famcnt);
    sort(famres.begin(), famres.end(), cmp);
    for (int i = 0; i<famres.size(); i++) {
        printf("%04d %d %.3f %.3f\n", famres[i]->id, famres[i]->ids.size(), famres[i]->avset, famres[i]->avarea);
    }
}