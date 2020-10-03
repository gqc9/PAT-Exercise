/*
 * 左右翻转二叉树的所有左右子树
 * 方法：存储时，颠倒左右子节点即可
 * 难点：根结点是所有左右结点中没有出现的那个结点
 */

#include <iostream>
#include <cstdio>
#include <string> // string
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int id;
    int left;
    int right;
};

// maxn=12时pta会报运行时错误，修改为maxn=30后AC
const int maxn = 12;
Node* nodes[maxn];
vector<int> in, level;

void inOrder(int idx) {
    if (nodes[idx]->left != -1) {
        inOrder(nodes[idx]->left);
    }
    in.push_back(nodes[idx]->id);
    if (nodes[idx]->right != -1) {
        inOrder(nodes[idx]->right);
    }
}

void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        level.push_back(idx);
        if (nodes[idx]->left != -1) {
            q.push(nodes[idx]->left);
        }
        if (nodes[idx]->right != -1) {
            q.push(nodes[idx]->right);
        }
    }
}

int main() {
    freopen("F:/bupt/PAT/1.txt","r",stdin);
    int n;
    scanf("%d", &n);
    int have[maxn];
    for (int i=0; i<n; i++) {
        nodes[i] = new Node;
        nodes[i]->id = i;
        string sa, sb;
        int a,b;
        cin >> sa >> sb;
        if (sa!="-") {
            a = stoi(sa);
            have[a] = 1;
            nodes[i]->right = a;
        } else {
            nodes[i]->right = -1;
        }
        if (sb!="-") {
            b = stoi(sb);
            have[b] = 1;
            nodes[i]->left = b;
        } else {
            nodes[i]->left = -1;
        }
    }
    int root = 0;
    for (int i=0; i<n; i++) {
        if (have[i] == 0) root = i;
    }

    levelOrder(root);
    for (int i=0; i<n; i++) {
        printf("%d", level.at(i));
        if (i!=n-1) printf(" ");
    }

    printf("\n");

    inOrder(root);
    for (int i=0; i<n; i++) {
        printf("%d", in.at(i));
        if (i!=n-1) printf(" ");
    }


    return 0;
}