/*
 * 非递归写法的树的前序遍历（使用栈）
 *  */

#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int left = -1;
    int right = -1;
};

const int maxn = 50;
vector<int> post;
Node* tree[maxn];

void postOrder(int idx) {
    if (tree[idx]->left != -1) {
        postOrder(tree[idx]->left);
    }
    if (tree[idx]->right != -1) {
        postOrder(tree[idx]->right);
    }
    post.push_back(idx);
}

int main() {
    freopen("1.txt","r",stdin);
    stack<int> s;
    int n, last, root;
    bool poped = false;
    scanf("%d", &n);
    for (int i=0; i<2*n; i++) {
        string op;
        cin >> op;
        if (op == "Push") {
            int idx; cin >> idx;
            if (i > 0) {
                if (poped) {
                    poped = false;
                }
                else {
                    last = s.top();
                }
                if (tree[last]->left == -1) tree[last]->left = idx;
                else tree[last]->right = idx;
            }
            s.push(idx);
            tree[idx] = new Node;
            if (i==0) root = idx;
        }
        else {  // Pop
            last = s.top();
            s.pop();
            poped = true;
        }
    }

    postOrder(root);
    for (int i=0; i<n; i++) {
        printf("%d", post.at(i));
        if (i!=n-1) printf(" ");
    }

    return 0;
}