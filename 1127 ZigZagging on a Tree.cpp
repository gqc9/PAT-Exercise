#include <cstdio>
#include <deque>
using namespace std;

struct Node {
    int data;
    Node* l;
    Node* r;
};

const int maxn = 35;
int n;
int in[maxn];
int post[maxn];

Node* create(int inL, int inR, int postL, int postR) {
    if (inL==inR) {
        return NULL;
    }
    int root = post[postR-1];
    int rootIdx;
    for (rootIdx=inL; rootIdx<inR;rootIdx++) {
        if (root == in[rootIdx]) break;
    }
    int numL = rootIdx - inL;
    Node* r = new Node;
    r->data = root;
    r->l = create(inL, rootIdx, postL, postL + numL);
    r->r = create(rootIdx+1, inR, postL+numL, postR-1);
    return r;
}

int main() {
    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&in[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d",&post[i]);
    }
    Node* root = create(0, n, 0, n);
    bool L2R = true;
    deque<Node*> q, newq;
    q.push_back(root);
    Node* node;
    int zigzag[maxn];
    int cur=0;
    while (!q.empty()) {
        L2R = !L2R;
        int count = q.size();
        while (count != 0) {
            if (L2R) {
                node = q.front();
                q.pop_front();
                if (node->l != NULL) newq.push_back(node->l);
                if (node->r != NULL) newq.push_back(node->r);
            }
            else {
                node = q.back();
                q.pop_back();
                if (node->r != NULL) newq.push_front(node->r);
                if (node->l != NULL) newq.push_front(node->l);
            }
            zigzag[cur++] = node->data;
            count--;
        }
        q = newq;
        newq.clear();
    }
    for (int i=0; i<n; i++) {
        if (i!=0) printf(" ");
        printf("%d", zigzag[i]);
    }
}