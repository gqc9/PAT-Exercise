/*
 *  前序遍历preorder，中序遍历inorder，后序遍历postorder
 *  由中序遍历、后序遍历推导、打印出这棵树的层序遍历
 */

#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

const int maxn = 30;
int in[maxn], post[maxn];
bool first = true;

Node* create(int postL, int postR, int inL, int inR) {
    if (postL==postR) return NULL;
    Node* node = new Node;
    int key = post[postR-1];
    node->data = key;
    int inRoot;
    for (inRoot=inL; inRoot<inR; inRoot++) {
        if (in[inRoot] == key) break;
    }
    int numLeft = inRoot - inL;
    node->left = create(postL, postL+numLeft, inL, inRoot);
    node->right = create(postL+numLeft, postR-1, inRoot+1, inR);
    return node;
}

// 打印层序遍历
void LevelOrder(Node* root) {
    if (root==NULL) return;
    queue<Node* > q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->left!=NULL) q.push(node->left);
        if (node->right!=NULL) q.push(node->right);
        if (!first) printf(" %d", node->data);
        else {
            printf("%d", node->data);
            first = false;
        }
    }
}

int main() {
    FILE* fp = fopen("1020.txt", "r");
    int num;
    fscanf(fp, "%d", &num);
    for (int i=0; i<num; i++) {
        fscanf(fp, "%d", &post[i]);
    }
    for (int i=0; i<num; i++) {
        fscanf(fp, "%d", &in[i]);
    }

    Node* root = create(0, num, 0, num);
    LevelOrder(root);

    return 0;
}