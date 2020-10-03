/*
 * 数组形式的树的层序遍历，需要区分不同层
 */

#include <cstdio>
// #include<iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn=110;
// struct Node {
//     vector<int> childs;
// };


int main() {
    // freopen("1004.txt","r",stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> tree[maxn];
    for (int i=0; i<m; i++) {
        vector<int> childs;
        int id, k, child;
        scanf("%d %d", &id, &k);
        for (int j=0; j<k; j++) {
            scanf("%d", &child);
            childs.push_back(child);
        }
        tree[id] = childs;
    }

    queue<int> q;
    q.push(1);
    vector<int> res;
    while(!q.empty()) {
        int count = q.size();
        int leaf = 0;
        while (count!=0) {
            int idx = q.front(); q.pop();
            for (int i=0; i<tree[idx].size(); i++) {
                q.push(tree[idx].at(i));
            }
            if (tree[idx].size() == 0) leaf++;
            count--;
        }
        res.push_back(leaf);
    }

    for (int i=0; i<res.size(); i++) {
        printf("%d", res.at(i));
        if (i!=res.size()-1) printf(" ");
    }

    return 0;
}