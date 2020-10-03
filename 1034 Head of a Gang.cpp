/*
 * 图的DFS（邻接矩阵形式）
 * 字符串id转数字id
 *  */

#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;

map<string, int> string2int;
map<int, string> int2string;
int mapSize = 0;

// 把字符串id转化成数字id，返回值为数字id
int s2iFunc(string str) {
    if (string2int.find(str) == string2int.end()) { // ***重要***如果str未在map里
        string2int[str] = mapSize;
        int2string[mapSize] = str;
        return mapSize++;
    }
    else {
        return string2int[str];
    }
}

const int maxSize = 2010;
int G[maxSize][maxSize]; // 图的边权，=0为两点不连通，用于计算gang的总权值
int weight[maxSize]; // 点权，用于找出头目权值
bool visited[maxSize];

map<string, int> res; // key=头目字符串id，value=gang的人数

// 注意后三个传入的是引用
void DFS(int idx, int& head, int& gangSize, int& gangW) {
    visited[idx] = true;
    gangSize++;
    // 检查头目
    if (weight[idx] > weight[head]) {
        head = idx;
    }
    for (int i=0; i<mapSize; i++) {
        if (G[idx][i] == 0) continue;
        gangW += G[idx][i];
        G[idx][i] = G[i][idx] = 0; // ***重要***删除这条边，防止回头，导致重复加
        if (!visited[i]) {
            DFS(i, head, gangSize, gangW);
        }
    }
}

int main() {
    freopen("1.txt","r",stdin);
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i=0; i<n; i++) {
        string str1, str2;
        int w;
        cin >> str1 >> str2 >> w;
        int id1 = s2iFunc(str1);
        int id2 = s2iFunc(str2);
        weight[id1] += w; weight[id2] += w; // 点权
        G[id1][id2] += w; G[id2][id1] += w; // 边权
    }

    for (int i=0; i<mapSize; i++) {
        if (visited[i]) continue;  // 访问过的节点就跳过
        // 下面是一个连通区域
        int head = i, gangSize = 0, gangW = 0; // 头目id，gang人数。gang总权值
        DFS(i, head, gangSize, gangW);
        if (gangW > k && gangSize > 2) {
            string sid = int2string[head];
            res[sid] = gangSize;
        }
    }

    // 输出
    printf("%d\n",res.size());
    for (auto it = res.begin(); it!=res.end(); it++) { // ***重要***注意map的迭代方式
        cout << it->first << " " << it->second << endl;
    }


    return 0;
}