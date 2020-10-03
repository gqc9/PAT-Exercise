/*
 * 非二叉树，用数组存储树
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 100;
struct Node {
    int weight;
    vector<int> childs;
    int totWeight;  // 从根节点到当前节点的权重之和
    vector<int> path;
} nodes[maxn];

bool cmp(vector<int> a, vector<int> b) {
    int end = min(a.size(), b.size());
    for (int i=0; i<end; i++) {
        if (a.at(i)==b.at(i)) continue;
        return a.at(i) > b.at(i);
    }
    return true;
}

int main() {
    FILE* fp = fopen("1053.txt", "r");
    int n;  // 总节点个数
    int m;  // 非叶子结点个数
    int s;  // 给定权重值
    fscanf(fp, "%d %d %d", &n, &m, &s);
    for (int i=0; i<n; i++) {
        fscanf(fp, "%d", &nodes[i].weight);
    }
    for (int i=0; i<m; i++) {   // m行
        int idx, k;
        fscanf(fp, "%d %d", &idx, &k);
        for (int j=0; j<k; j++) {
            int tmp;
            fscanf(fp, "%d", &tmp);
            nodes[idx].childs.push_back(tmp);
        }
    }

    vector<vector<int>> res;
    queue<int> q;
    nodes[0].path.push_back(nodes[0].weight);
    nodes[0].totWeight = nodes[0].weight;
    q.push(0);

    while(!q.empty()) {
        int idx = q.front();
        q.pop();
        for (int i=0; i<nodes[idx].childs.size(); i++) {
            int child = nodes[idx].childs.at(i);
            nodes[child].path = nodes[idx].path;
            nodes[child].path.push_back(nodes[child].weight);
            nodes[child].totWeight = nodes[child].weight + nodes[idx].totWeight;
            if (nodes[child].childs.size()==0 && nodes[child].totWeight==s) {
                res.push_back(nodes[child].path);
            }
            q.push(child);
        }
    }

    sort(res.begin(), res.end(), cmp);

    for (int i=0; i<res.size(); i++) {
        vector<int> tmpV = res.at(i);
        for (int j=0; j<tmpV.size(); j++) {
            printf("%d", tmpV.at(j));
            if (j!=tmpV.size()-1) printf(" ");
        }
        printf("\n");
    }
}