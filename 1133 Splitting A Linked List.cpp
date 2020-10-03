#include<cstdio>
#include<vector>
using namespace std;

struct Node {
    int addr;
    int data;
    int next;
};

const int maxn = 100010;
const int maxid = 100010;
Node* list[maxid];

int main() {
    freopen("1.txt","r",stdin);
    int root,n,k,a,d,ne1;
    scanf("%d%d%d",&root,&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%d%d%d",&a,&d,&ne1);
        list[a] = new Node;
        list[a]->addr = a;
        list[a]->data = d;
        list[a]->next = ne1;
    }
    vector<int> nega;
    vector<int> below;
    vector<int> above;
    int node = root;
    while (node != -1) {
        if (list[node]->data < 0) {
            nega.push_back(node);
        }
        else if (list[node]->data <= k) {
            below.push_back(node);
        }
        else if (list[node]->data > k) {
            above.push_back(node);
        }
        node = list[node]->next;
    }
    int cnt[3] = { nega.size(), below.size(), above.size() };
    Node* tmp;
    for (int i=0; i<nega.size(); i++) {
        printf("%05d %d ", list[nega[i]]->addr, list[nega[i]]->data);
        if (i < nega.size()-1)
            printf("%05d\n", list[nega[i+1]]->addr);
        else if (cnt[1])
            printf("%05d\n", list[below[0]]->addr);
        else if (cnt[2])
            printf("%05d\n", list[above[0]]->addr);
        else {
            printf("-1\n");
            return 0;
        }
    }
    for (int i=0; i<below.size(); i++) {
        printf("%05d %d ", list[below[i]]->addr, list[below[i]]->data);
        if (i < below.size()-1)
            printf("%05d\n", list[below[i+1]]->addr);
        else if (cnt[2])
            printf("%05d\n", list[above[0]]->addr);
        else {
            printf("-1\n");
            return 0;
        }
    }
    for (int i=0; i<above.size(); i++) {
        printf("%05d %d ", list[above[i]]->addr, list[above[i]]->data);
        if (i < above.size()-1)
            printf("%05d\n", list[above[i+1]]->addr);
        else {
            printf("-1\n");
            return 0;
        }
    }
    return 0;
}