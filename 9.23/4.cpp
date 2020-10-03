#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int coup[maxn];
int item[maxn];
//map<int, int> m;
vector<int> v;

int main() {
	freopen("1.txt", "r", stdin);
	int n, d, cp;
	scanf("%d%d", &n, &d);
	for (int i = 0; i<n; i++) {
		scanf("%d", &item[i]);
	}
	for (int i = 0; i<n; i++) {
		scanf("%d", &coup[i]);
		
	}
	sort(item, item+n);
	sort(coup, coup+n);

	int use = 0;
	for (int i = 0; i<n&&use<d; i++) {
		for (int j = 0; j<n; j++) {
			if (use>=d)break;

		}
	}

	for (int j = 0; j<n; j++) {
		//m[item[j]-cp]++;
		v.push_back(item[j]-cp);
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i<v.size(); i++) {
		if (d<v[i]) break;
		d -= v[i];
		cnt++;
	}
	printf("%d %d", cnt, d);
}