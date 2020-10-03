/*
 * AVL
 *  */

#include <cstdio>
#include <algorithm>
using namespace std;


struct Node {
    int data;
    Node* left, * right;
    int height;
};

Node* newnode(int d) {
    Node* n = new Node;
    n->data = d;
    n->height = 1;
    n->left = n->right = NULL;
    return n;
}

int getHeight(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

void updateHeight(Node* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

int getBalanceFactor(Node* node) {
    return getHeight(node->left) - getHeight(node->right);
}

// 左旋。注意传入的是root的引用
void LeftRotate(Node* &root) {
    Node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

// 右旋。注意传入的是root的引用
void RightRotate(Node* &root) {
    Node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void insert(Node* &node, int key) {
    if (node == NULL) {
        node = newnode(key);
        return;
    }
    if (node->data > key) {
        insert(node->left, key);
        updateHeight(node);
        if (getBalanceFactor(node) == 2) {
            if (getBalanceFactor(node->left) == 1) {
                RightRotate(node);
            }
            else if (getBalanceFactor(node->left) == -1){
                LeftRotate(node->left);
                RightRotate(node);
            }
        }
    }
    else {
        insert(node->right, key);
        updateHeight(node);
        if (getBalanceFactor(node) == -2) {
            if (getBalanceFactor(node->right) == -1) {
                LeftRotate(node);
            }
            else if (getBalanceFactor(node->right) == 1){
                RightRotate(node->right);
                LeftRotate(node);
            }
        }
    }
}

int main() {
    freopen("1.txt", "r", stdin);
    int n, v;
    scanf("%d",&n);
    Node* root = NULL;
    for (int i=0; i<n; i++) {
        scanf("%d", &v);
        insert(root, v);
    }
    printf("%d",root->data);
    return 0;
}