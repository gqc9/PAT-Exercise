/*
 * 9.5PAT考试第二题
 *  */

#include <cstdio>

const int maxn = 1010;

int main2() {
	freopen("1.txt", "r", stdin);
	int n,m;
	int price[maxn];
	int l = 0;
	int cnt = 0;
	scanf("%d %d", &n,&m);
	for (int i = 0; i<n; i++) {
		scanf("%d", &price[i]);
		if (i==0 && price[i] <= m) {
			cnt++;
			continue;
		}
		int sum = 0;
		for (int j = i; j>=l; j--) {
			sum += price[j];
			if (sum > m) {
				l = j+1;
				break;
			}
			else cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}