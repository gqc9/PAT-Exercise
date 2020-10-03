/*
 * 给出树的前序遍历，判断是不是二叉搜索树。是的话，给出后序遍历
 * 方法：前序遍历就是树的构造顺序。
 * 运行结果：7/7
 */

#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1000;
vector<int> input, pre, preMirror, post, postMirror;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// 插入节点、创建一颗二叉搜索树
void insert(Node* &node, int key) {
    if (node == NULL) {
        node = new Node;
        node->data = key;
        node->left = node->right = NULL;
        return;
    }
    if (node->data <= key) {
        insert(node->right, key);
    }
    else {
        insert(node->left, key);
    }
}

// 前序遍历
void preOrder(Node* node) {
    if (node==NULL) return;
    pre.push_back(node->data);
    if (node->left !=NULL) preOrder(node->left);
    if (node->right !=NULL) preOrder(node->right);
}

// 前序遍历它的镜像树
void preOrderMirror(Node* node) {
    if (node==NULL) return;
    preMirror.push_back(node->data);
    if (node->right !=NULL) preOrderMirror(node->right);
    if (node->left !=NULL) preOrderMirror(node->left);
}

// 后序遍历
void postOrder(Node* node) {
    if (node==NULL) return;
    if (node->left !=NULL) postOrder(node->left);
    if (node->right !=NULL) postOrder(node->right);
    post.push_back(node->data);
}

// 后序遍历它的镜像树
void postOrderMirror(Node* node) {
    if (node==NULL) return;
    if (node->right !=NULL) postOrderMirror(node->right);
    if (node->left !=NULL) postOrderMirror(node->left);
    postMirror.push_back(node->data);
}

int main() {
    freopen("1043.txt","r",stdin);
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        input.push_back(tmp);
    }

    // 建立二叉树
    Node* root = new Node;
    root->data = input[0];
    root->left = root->right = NULL;

    for (int i=1; i<n; i++) {
        insert(root, input[i]);
    }

    // 判断输入的是不是二叉搜索树的前序遍历
    preOrder(root);
    if (pre == input) {
        printf("YES\n");
        postOrder(root);
        for (int i=0; i<n; i++) {
            printf("%d", post.at(i));
            if (i != n-1) printf(" ");
        }
        return 0;
    }
    // 判断它的镜像
    preOrderMirror(root);
    if (preMirror == input) {
        printf("YES\n");
        postOrderMirror(root);
        for (int i=0; i<n; i++) {
            printf("%d", postMirror.at(i));
            if (i != n-1) printf(" ");
        }
    }
    else {
        printf("NO\n");
    }
    return 0;
}