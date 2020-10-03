/*
 *  前序遍历preorder，中序遍历inorder，后序遍历postorder
 *  由前序遍历、中序遍历推导、打印出这棵树的后序遍历
 */

#include <cstdio>

const int maxn = 30; // 数组的最大长度

struct Node {
    int data;
    Node* left;
    Node* right;
};  // 树的一个节点

int pre[maxn], in[maxn];

// 包括preL、inL，不包括preR、inR
Node* create(int preL, int preR, int inL, int inR) {
    if (preL==preR || inL==inR) return NULL; // 递归结束条件
    Node* root = new Node;
    root->data = pre[preL];
    int inRoot;
    for (inRoot=inL; inRoot<inR; inRoot++) {
        if (pre[preL]==in[inRoot]) break;
    }
    int numLeft = inRoot - inL; // 左子树节点数
    root->left = create(preL+1, preL+numLeft+1, inL, inRoot);
    root->right = create(preL+numLeft+1, preR, inRoot+1, inR);

    return root;
}

// 打印后序遍历结果
void printPost(Node* node) {
    if (node==NULL) return;
    printPost(node->left);
    printPost(node->right);
    printf("%d ", node->data);
}

int main() {
    FILE* fp = fopen("1020-1.txt", "r");
    int num;
    fscanf(fp, "%d", &num);
    for (int i=0; i<num; i++) {
        fscanf(fp, "%d", &pre[i]);
    }
    for (int i=0; i<num; i++) {
        fscanf(fp, "%d", &in[i]);
    }

    Node* root = create(0, num, 0, num);
    printPost(root);
    return 0;
}