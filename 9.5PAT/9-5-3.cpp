 /*
  * 9.5PAT考试第三题
  * 前中序遍历求树
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

const int maxn = 100;
int in[maxn];
int pre[maxn];

Node* create(int inL, int inR, int preL, int preR) {
	if (inL==inR) return NULL;
	int root = pre[preL];
	Node* res = new Node;
	res->data = root;
	// find root in inOrder
	int inRoot;
	for (inRoot = inL; inRoot<inR; inRoot++) {
		if (in[inRoot] == root) break;
	}
	int numLeft = inRoot - inL;
	res->left = create(inL, inRoot, preL+1, preL+1+numLeft);
	res->right = create(inRoot+1, inR, preL+1+numLeft, preR);

	return res;
}

int main() {
	freopen("1.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &in[i]);
	}
	for (int i = 0; i<n; i++) {
		scanf("%d", &pre[i]);
	}

	Node* root = create(0, n, 0, n);

	bool level[maxn];
	fill(level, level+n, false);
	int l = 0;
	vector<int> res;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int cnt = q.size();
		while (cnt != 0) {
			Node* node = q.front();
			q.pop();
			if (!level[l]) {	//这一层还没有加入vector
				res.push_back(node->data);
				level[l] = true;
			}
			if (node->left!=NULL) {
				q.push(node->left);
			}
			if (node->right!=NULL) {
				q.push(node->right);
			}
			cnt--;
		}
		l++;
	}

	for (int i = 0; i<res.size(); i++) {
		if (i!=0) printf(" ");
		printf("%d", res[i]);
	}

	return 0;
}