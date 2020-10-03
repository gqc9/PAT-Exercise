/*
 * 判断是否是完全二叉树
 *  */

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int left, right;
};

const int maxn = 25;
Node* nodes[maxn];
bool have[maxn];

int main() {
    freopen("1.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        nodes[i] = new Node;
        string a, b;
        cin >> a >> b;
        if (a!="-") {
            nodes[i]->left = stoi(a);
            have[stoi(a)] = true;
        }
        else {
            nodes[i]->left = -1;
        }
        if (b!="-") {
            nodes[i]->right = stoi(b);
            have[stoi(b)] = true;
        }
        else {
            nodes[i]->right = -1;
        }
    }

    int root;
    for (int i=0; i<n; i++) {
        if (!have[i]) {
            root = i;
            break;
        }
    }

    queue<int> q;
    q.push(root);
    bool flag = false;
    int idx = root;
    while (!q.empty()) {
        int count = q.size();
        while (count!=0) {
            idx = q.front(); q.pop();
            if (nodes[idx]->left == -1) //没有左
                flag = true;

            if (flag) {
                if (nodes[idx]->left!=-1 || nodes[idx]->right!=-1) {
                    printf("NO %d", root);
                    return 0;
                }
            }

            if (nodes[idx]->right == -1)  //没有右
                flag = true;

            if (nodes[idx]->left != -1) q.push(nodes[idx]->left);
            if (nodes[idx]->right != -1) q.push(nodes[idx]->right);

            count--;
        }
    }

    printf("YES %d",idx);
    return 0;
}