//#define _CRT_SECURE_NO_WARNINGS
//
//#include<cstdio>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
//
//struct Node {
//	set<int> ids;
//	int totsc = 0;
//};
//
//struct Person {
//	int score;
//};
//
//const int maxn = 1010;
//const int maxid = 10010;
//int father[maxid];
//Node* nodes[maxid];
//Person* people[maxid];
//
//bool cmp(Node* a, Node* b) {
//	if (a->totsc != b->totsc) {
//		return a->totsc > b->totsc;
//	}
//	if (a->ids.size()!=b->ids.size()) {
//		return a->ids.size() < b->ids.size();
//	}
//	return *(a->ids.begin()) < *(b->ids.begin());
//}
//
//void init() {
//	for (int i = 0; i<maxid; i++) {
//		father[i] = i;
//	}
//}
//
//int findFather(int idx) {
//	//return (father[idx]==idx) ? idx : father[idx] = findFather(idx);
//	while (father[idx]!=idx) {
//		idx = father[idx];
//	}
//	return idx;
//}
//
//void Union(int a, int b) {
//	int fa = findFather(a);
//	int fb = findFather(b);
//	father[fb] = fa;
//	if (nodes[fa] == NULL) {
//		nodes[fa] = new Node;		
//	}
//	if (nodes[fb]!=NULL) {
//		if (nodes[fb]->ids.size()!=0) {
//			nodes[fa]->ids.insert(nodes[fb]->ids.begin(), nodes[fb]->ids.end());
//		}
//		//nodes[fa]->totsc = nodes[fb]->totsc;
//	}
//	nodes[fa]->ids.insert(fa);
//	nodes[fa]->ids.insert(fb);
//}
//
//int main() {
//	freopen("1.txt", "r", stdin);
//	init();
//	int n, id, k, sc;
//	vector<int> idlist;
//	scanf("%d", &n);
//	for (int i = 0; i<n; i++) {
//		int ti[maxn];
//		scanf("%d%d", &id,&k);
//		idlist.push_back(id);
//		for (int j = 0; j<k; j++) {
//			scanf("%d", &ti[j]);
//		}
//		scanf("%d", &sc);
//		int fi = findFather(id);
//		if (nodes[fi] == NULL) {
//			nodes[fi] = new Node;
//		}
//		nodes[fi]->ids.insert(id);
//		for (int j = 0; j<k; j++) {
//			Union(id,ti[j]);
//		}
//		people[id] = new Person;
//		people[id]->score = sc;
//	}
//	
//	vector<Node*> res;
//	bool vis[maxid];
//	fill(vis, vis+maxid, false);
//	for (int i = 0; i<idlist.size(); i++) {
//		int fa = findFather(idlist[i]);
//		nodes[fa]->totsc += people[idlist[i]]->score;
//		if (!vis[fa]) {
//			res.push_back(nodes[fa]);
//			vis[fa] = true;
//		}
//	}
//
//	sort(res.begin(), res.end(), cmp);
//
//	printf("%d\n", res.size());
//	for (int i = 0; i<res.size(); i++) {
//		printf("%04d %d %d\n", *(res[i]->ids.begin()), res[i]->ids.size(), res[i]->totsc);
//	}
//
//	return 0;
//
//}