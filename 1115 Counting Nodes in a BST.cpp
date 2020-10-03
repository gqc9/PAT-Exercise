/*
 * 二叉搜索树的构造及层序遍历
 * 分别找出最后两层的节点个数
 *  */

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

const int maxn = 1010;
int input[maxn];

void insert(Node* &node, int key) {
    if (node == NULL) {
        node = new Node;
        node->data = key;
        node->left = node->right = NULL;
        return;
    }
    if (key > node->data) {
        insert(node->right, key);
    }
    else {
        insert(node->left, key);
    }
}

int main() {
    freopen("1.txt","r",stdin);
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int tmp;
        scanf("%d",&tmp);
        input[i] = tmp;
    }

    Node* root = new Node;
    root->data = input[0];
    root->left = root->right = NULL;
    for (int i=1; i<n; i++) {
        insert(root, input[i]);
    }

    queue<Node*> q;
    q.push(root);
    int lowest=0, low2=0;
    while (!q.empty()) {
        int count = q.size();
        low2 = lowest;
        lowest = count;
        while (count!=0) {
            Node* node = q.front();
            q.pop();
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
            count--;
        }
    }

    printf("%d + %d = %d", lowest, low2, lowest+low2);

    return 0;
}