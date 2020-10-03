/*
 * 9.5PAT考试第四题
 * Dijkstra+DFS
 *  */

#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int INF = 1000000000;
const int maxn = 1010;
int s[maxn][maxn];
int d[maxn][maxn];
int n;
vector<int> paths[maxn];
set<int> roots;

void findRoot(int idx) {
	bool flag = false;
	for (int i = 0; i<n; i++) {
		if (s[i][idx] != 0) {
			flag = true;
			findRoot(i);
		}
	}
	if (!flag) roots.insert(idx);
}

void Dij(int start) {
	int dist[maxn];
	fill(dist, dist+n, INF);
	bool vis[maxn];
	fill(vis, vis+n, false);
	dist[start] = 0;
	paths[start].push_back(start);
	int mid = -1, minD = INF;
	for (int i = 0; i<n; i++) {
		if (!vis[i] &&/* s[i][start]!=0 && */dist[i]<minD) {
			mid = i;
			minD = dist[i];
		}
	}
	if (mid==-1) return;
	vis[mid] = true;
	for (int i = 0; i<n; i++) {
		if (vis[i] || s[i][mid]==0) continue;
		if (dist[i] > s[i][mid] + dist[mid]) {
			dist[i] = s[i][mid] + dist[mid];
			paths[i].clear();
			paths[i].push_back(mid);
		}
		else if (dist[i] == s[i][mid] + dist[mid]) {
			paths[i].push_back(mid);
		}
	}
}

vector<int> curpath;
vector<int> bestpath;
int maxV = 0;

void DFS(int idx, int cost) {
	if (paths[idx][0] == idx) {
		if (cost>maxV) {
			curpath.push_back(idx);
			bestpath = curpath;
			curpath.pop_back();
			maxV = cost;
		}
		return;
	}
	for (int i = 0; i<paths[idx].size(); i++) {
		curpath.push_back(idx);
		DFS(paths[idx][i], cost+d[idx][paths[idx][i]]);
		curpath.pop_back();
	}
}

int main() {
	freopen("1.txt", "r", stdin);

	int m, k, q, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++) {
		scanf("%d %d", &a, &b);
		scanf("%d %d", &s[a][b], &d[a][b]);
	}

	scanf("%d", &k);
	printf("Okay.\n");
	for (int i = 0; i<k; i++) {
		scanf("%d", &q);
		//q = 1;
		roots.clear();
		findRoot(q);
		if (*roots.begin() == q) {
			printf("You may take test %d directly.\n", q);
			continue;
		}


		Dij(q);

		for (auto i = roots.begin(); i!=roots.end(); i++) {
			DFS(*i, 0);
		}

		for (int j = 0; j<bestpath.size(); j++) {
			if (j!=0) printf("->");
			printf("%d", bestpath[j]);
		}
		printf("\n");

	}


	return 0;
}