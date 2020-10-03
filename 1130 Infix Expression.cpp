/*
 * 树的中序遍历
 * 4/5
 */

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    int l;
    int r;
};

const int maxn = 30;
Node* nodes[maxn];
string ans = "";

void DFS(int idx) {
    if (idx == -1) return;
    if (nodes[idx]->l == -1 && nodes[idx]->r == -1) {
        ans += nodes[idx]->data;
        return;
    }
    ans += "(";
    DFS(nodes[idx]->l);
    ans += nodes[idx]->data;
    DFS(nodes[idx]->r);
    ans += ")";
}

int main() {
    freopen("1.txt", "r", stdin);
    int n;
    string data;    //******为什么这句话不能删？？？？？*******
    scanf("%d", &n);
    bool have[maxn];
    fill(have, have+n, false);
    for (int i = 1; i<=n; i++) {
        nodes[i] = new Node;
        cin >> nodes[i]->data >> nodes[i]->l >> nodes[i]->r;
        if (nodes[i]->l != -1) have[nodes[i]->l] = true;
        if (nodes[i]->r != -1) have[nodes[i]->r] = true;
    }
    int root = -1;
    for (int i = 1; i<=n; i++) {
        if (!have[i]) {
            root = i;
            break;
        }
    }

    DFS(root);
    ans = ans.substr(1, ans.size()-2);
    cout << ans;
}